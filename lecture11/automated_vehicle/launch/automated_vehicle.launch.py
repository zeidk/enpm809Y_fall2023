"""
Launch file for the automated_vehicle package
"""
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """
    Main function for the launch file
    """
    # find the parameter file
    parameter_file = os.path.join(
        get_package_share_directory('automated_vehicle'),
        'config',
        'av_params.yaml'
    )
    # center_camera = Node(
    #     package="automated_vehicle",
    #     executable="center_cam",
    #     parameters=[
    #         {'message_height': 480},
    #         {'message_width': 640},
    #         {'message_encoding': 'grayscale'},
    #         {'name': 'center_front_cam'}
    #     ]
    # )
    center_camera = Node(
        package="automated_vehicle",
        executable="camera",
        parameters=[parameter_file]
    )

    left_camera = Node(
        package="automated_vehicle",
        executable="camera",
        parameters=[parameter_file],    # parameter file
        name='left_camera',                # node remapping
        remappings=[                    # topic remapping
            ('/image', '/left_image')
        ]
    )

    center_camera = Node(
        package="automated_vehicle",
        executable="camera",
        parameters=[parameter_file],    # parameter file
        name='center_camera',                # node remapping
        remappings=[                    # topic remapping
            ('/image', '/center_image')
        ]
    )

    right_camera = Node(
        package="automated_vehicle",
        executable="camera",
        parameters=[parameter_file],    # parameter file
        name='right_camera',                # node remapping
        remappings=[                    # topic remapping
            ('/image', '/right_image')
        ]
    )

    ld = LaunchDescription()
    ld.add_action(left_camera)
    ld.add_action(center_camera)
    ld.add_action(right_camera)
    return ld
