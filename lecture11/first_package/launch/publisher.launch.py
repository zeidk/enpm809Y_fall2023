"""
simple launch file to launch both nodes
"""
from launch import LaunchDescription
from launch_ros.actions import Node
# This function is needed


def generate_launch_description():
    """
    This function is needed
    """

    ld = LaunchDescription()
    publisher = Node(
        package="first_package",
        executable="light_switcher_pub"
    )
    ld.add_action(publisher)
    return ld
