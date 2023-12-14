#!/usr/bin/env python3

import math
import yaml
import xml.etree.ElementTree as ET
from random import randint

import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import ParameterDescriptor

from rclpy.qos import QoSProfile, DurabilityPolicy

from final_project.tf2_geometry_msgs import do_transform_pose
from final_project.utilities import quaternion_from_euler, euler_from_quaternion, convert_pi_string_to_float

from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

from geometry_msgs.msg import (
    Pose,
    PoseStamped,
    Vector3
)



from gazebo_msgs.srv import SpawnEntity
from std_srvs.srv import Empty
from final_project.spawn_params import (
    SpawnParams,
    SensorSpawnParams,
    PartSpawnParams)


class PartInfo:
    part_heights = {
        'battery': 0.04,
        'sensor': 0.07,
        'pump': 0.12,
        'regulator': 0.07,
    }

    def __init__(self):
        self.type = None
        self.color = None
        self.rotation = '0'
        self.flipped = False
        self.height = None


class EnvironmentStartup(Node):
    def __init__(self):
        super().__init__('environment_startup_node')

        self.declare_parameter('user_config_path', '',
                               ParameterDescriptor(description='Path of the user\'s configuration yaml file'))

        self.user_config = self.read_yaml(
            self.get_parameter('user_config_path').get_parameter_value().string_value)

        # Create service client to spawn objects into gazebo
        self.spawn_client = self.create_client(SpawnEntity, '/spawn_entity')

        # Setup TF listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
 
        
    def convert_part_type_to_int(self, part_type):
        """Converts a part type to an integer.
        - battery: Part.BATTERY
        - pump: Part.PUMP
        - sensor: Part.SENSOR
        - regulator: Part.REGULATOR

        Args:
            part_type (str): The type of a part in string format.

        Returns:
            int: The type of a part in integer format.
        """

        options = {
            'battery': Part.BATTERY,
            'pump': Part.PUMP,
            'sensor': Part.SENSOR,
            'regulator': Part.REGULATOR
        }

        found_type = options.get(part_type)

        if found_type in [Part.BATTERY, Part.PUMP, Part.SENSOR, Part.REGULATOR]:
            return found_type
        else:
            self.get_logger().fatal(
                f"Part type '{part_type}' is not correct. Check spelling.")
            return None


    def convert_part_color_to_int(self, part_color):
        """Converts a part color to an integer.
        - red: Part.RED
        - green: Part.GREEN
        - blue: Part.BLUE
        - orange: Part.ORANGE
        - purple: Part.PURPLE

        Args:
            part_color (str): The color of a part in string format.

        Returns:
            int: The color of a part in integer format.
        """

        options = {
            'red': Part.RED,
            'green': Part.GREEN,
            'blue': Part.BLUE,
            'orange': Part.ORANGE,
            'purple': Part.PURPLE
        }

        found_type = options.get(part_color)

        if found_type in [Part.RED, Part.GREEN, Part.BLUE, Part.ORANGE, Part.PURPLE]:
            return found_type
        else:
            self.get_logger().fatal(
                f"Part color '{part_color}' is not correct. Check spelling.")
            return None


    
    def spawn_sensors(self):
        try:
            user_sensors = self.user_config['sensors']
        except (TypeError, KeyError):
            self.get_logger().warn("No sensors found in config")
            user_sensors = []

        if not user_sensors:
            user_sensors = []

        # Spawn user sensors
        for sensor_name in user_sensors:
            sensor_type = user_sensors[sensor_name]['type']
            xyz = user_sensors[sensor_name]['pose']['xyz']
            rpy = user_sensors[sensor_name]['pose']['rpy']

            if 'visualize_fov' in user_sensors[sensor_name].keys():
                vis = user_sensors[sensor_name]['visualize_fov']
            else:
                vis = False

            params = SensorSpawnParams(
                sensor_name, sensor_type, visualize=vis, xyz=xyz, rpy=rpy)
            self.spawn_entity(params)

    def spawn_entity(self, params: SpawnParams, wait=True) -> bool:
        self.spawn_client.wait_for_service()

        # self.get_logger().info(f'Spawning: {params.name}')

        req = SpawnEntity.Request()

        req.name = params.name
        req.xml = params.xml
        req.initial_pose = params.initial_pose
        req.robot_namespace = params.robot_namespace
        req.reference_frame = params.reference_frame

        future = self.spawn_client.call_async(req)

        if wait:
            rclpy.spin_until_future_complete(self, future)
            return future.result().success
        else:
            return True

    def parse_part_info(self, part_info):
        part = PartInfo()

        try:
            part.type = part_info['type']
            part.height = PartInfo.part_heights[part.type]
        except KeyError:
            self.get_logger().warn("Part type is not specified")
            return (False, part)

        try:
            part.color = part_info['color']
        except KeyError:
            self.get_logger().warn("Part color is not specified")
            return (False, part)

        try:
            part.rotation = str(part_info['rotation'])
        except KeyError:
            pass


        if not part.type in PartSpawnParams.part_types:
            self.get_logger().warn(
                f"{part_info['type']} is not a valid part type")
            return (False, part)

        if not part.color in PartSpawnParams.colors:
            self.get_logger().warn(
                f"{part_info['color']} is not a valid part color")
            return (False, part)

        return (True, part)

    def read_yaml(self, path):
        with open(path, "r") as stream:
            try:
                return yaml.safe_load(stream)
            except yaml.YAMLError:
                self.get_logger().error("Unable to read configuration file")
                return {}

    
