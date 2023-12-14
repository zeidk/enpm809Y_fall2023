import os
import yaml
import rclpy.logging
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    OpaqueFunction,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.conditions import IfCondition

from ament_index_python.packages import get_package_share_directory, PackageNotFoundError


def launch_setup(context, *args, **kwargs):
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    x_pose = LaunchConfiguration('x_pose', default='1')
    y_pose = LaunchConfiguration('y_pose', default='-1.590131')
    yaw_pose = LaunchConfiguration('yaw_pose', default='-1.5707')
    # Set the path to this package.
    pkg_share = FindPackageShare(package='final_project').find('final_project')

    # Set the path to the world file
    world_file_name = 'final.world'
    world_path = os.path.join(pkg_share, 'worlds', world_file_name)

    user_config_path = os.path.join(
        pkg_share, 'config', "sensors.yaml")

    if not os.path.exists(user_config_path):
        rclpy.logging.get_logger('Launch File').fatal(
            f"Sensor configuration 'sensors.yaml' not found in config directory: {user_config_path}.")
        exit()

    # Gazebo node
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [FindPackageShare("gazebo_ros"), "/launch", "/gazebo.launch.py"]
        ),
        launch_arguments={
            'world': world_path,
        }.items()
    )

    # Sensor TF
    sensor_tf_broadcaster = Node(
        package='final_project',
        executable='sensor_tf_broadcaster.py',
        output='screen',
        arguments=[user_config_path],
        parameters=[
            {"use_sim_time": True},
        ]
    )

    # Environment Startup
    environment_startup = Node(
        package='final_project',
        executable='environment_startup_node.py',
        output='screen',
        parameters=[
            {'user_config_path': user_config_path},
            {"use_sim_time": True},
        ],
    )

    part_spawner_cmd = Node(
        package='final_project',
        executable='part_spawner.py',
        output='screen'
    )

    start_aruco_detection_node_cmd = Node(
        package='ros2_aruco',
        executable='aruco_node',
        output='screen')
    
    map_path = os.path.join(
        get_package_share_directory('final_project'),
        'maps',
        'final2_map.yaml')

    # Navigation2 node
    turtlebot3_navigation2_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [FindPackageShare("turtlebot3_navigation2"),
             "/launch", "/navigation2.launch.py"]
        ),
        launch_arguments={
            'use_sim_time': 'true',
            'map': map_path,
        }.items()
    )

    # static_broadcaster = Node(
    #     package='final_project',
    #     executable='object_tf_broadcaster.py',
    #     output='screen')

    static_transform_cmd = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        output='screen',
        arguments=[
            '0',  # x
            '0',  # y
            '0',  # z
            '0',  # r
            '0',  # p
            '0',  # y
            'world',  # frame_id
            'map'   # child_frame_id
        ]
        # arguments=[
        #     '1.61816',  # x
        #     '1.01542',  # y
        #     '0.0183318',  # z
        #     '0.00229583',  # qx
        #     '0.00238136',  # qy
        #     '-0.723482',  # qz
        #     '-0.690335',  # qw
        #     'world',  # frame_id
        #     'map'   # child_frame_id
        # ]
    )

    launch_file_dir = os.path.join(
        get_package_share_directory('final_project'), 'launch')

    robot_state_publisher_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'robot_state_publisher.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    spawn_turtlebot_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'spawn_turtlebot3.launch.py')
        ),
        launch_arguments={
            'x_pose': x_pose,
            'y_pose': y_pose,
            'yaw_pose': yaw_pose
        }.items()
    )

    nodes_to_start = [
        gazebo,
        environment_startup,
        part_spawner_cmd,
        start_aruco_detection_node_cmd,
        robot_state_publisher_cmd,
        spawn_turtlebot_cmd,
        turtlebot3_navigation2_cmd,
        sensor_tf_broadcaster,
        static_transform_cmd
    ]

    return nodes_to_start


def generate_launch_description():
    declared_arguments = []

    declared_arguments.append(
        DeclareLaunchArgument("sensor_config", default_value="sensors",
                              description="name of user configuration file")
    )

    return LaunchDescription(declared_arguments + [OpaqueFunction(function=launch_setup)])
