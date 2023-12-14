#!/usr/bin/env python3

import rclpy
from final_project.tf_broadcaster import TFBroadcaster
from final_project.utilities import pose_info


def main():
    rclpy.init()

    objects_tf_broadcaster = TFBroadcaster("objects_tf_broadcaster")

    objects_tf_broadcaster.generate_transform(
        "odom", "world", pose_info([0, 0, 0], [0, 0, 0]))
    # objects_tf_broadcaster.generate_transform(
    #     "world", "map", pose_info([0, 0, 0], [0, 0, 0]))
    # Send tf transforms
    objects_tf_broadcaster.send_transforms()

    try:
        rclpy.spin(objects_tf_broadcaster)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()


if __name__ == '__main__':
    main()
