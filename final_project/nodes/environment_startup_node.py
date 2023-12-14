#!/usr/bin/env python3

import sys
import rclpy
import time

from final_project.environment_startup import EnvironmentStartup

def main():
    rclpy.init()

    startup_node = EnvironmentStartup()

    # Wait five seconds for gazebo to start up
    time.sleep(2)

    # Spawn sensors
    startup_node.spawn_sensors()

    # Spawn parts in bins
    # startup_node.spawn_bin_parts()

    try:
        rclpy.spin(startup_node)
    except:
        startup_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()