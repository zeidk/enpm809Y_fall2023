#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from gazebo_msgs.srv import SpawnEntity
from final_project.spawn_params import SpawnParams
from final_project.spawn_params import PartSpawnParams


class PartSpawner(Node):
    def __init__(self):
        super().__init__('part_spawner')

        # Create service client to spawn objects into gazebo
        self.spawn_client = self.create_client(SpawnEntity, '/spawn_entity')

    def spawn_part(self, name, type, color, xyz, rpy):
        params = PartSpawnParams(name, type, color, xyz=xyz, rpy=rpy)

        self.spawn_entity(params)

    def spawn_entity(self, params: SpawnParams) -> bool:
        self.spawn_client.wait_for_service()

        self.get_logger().info(f'Spawning: {params.name}')

        req = SpawnEntity.Request()

        req.name = params.name
        req.xml = params.xml
        req.initial_pose = params.initial_pose
        req.robot_namespace = params.robot_namespace
        req.reference_frame = params.reference_frame

        future = self.spawn_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)

        return future.result().success


if __name__ == "__main__":
    rclpy.init()

    part_spawner = PartSpawner()
    part_spawner.spawn_part("blue_battery_99", "battery", "blue", [
                            1.609075, 2.520909, 1], [0, 0, 0.78539816339])
    part_spawner.spawn_part("green_battery_99", "battery",
                            "green", [1.918326, -2.504197, 1], [0, 0, 1.57])
    part_spawner.spawn_part("red_battery_99", "battery",
                            "red", [6.235279, -2.351816, 1], [0, 0, -1.57])
    part_spawner.spawn_part("orange_battery_99", "battery",
                            "orange", [6.338, 1.335, 0.38], [0, 0, 0])
    part_spawner.spawn_part("purple_battery_99", "battery",
                            "purple", [4.269588, 0.469212, 1], [0, 0.0, -0.78539816339])

    part_spawner.destroy_node()
    rclpy.shutdown()
