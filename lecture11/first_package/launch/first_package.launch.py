"""
simple launch file to launch both nodes
"""
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
# This function is needed


def generate_launch_description():
    """
    This function is needed
    """

    ld = LaunchDescription()
    
    publisher = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [FindPackageShare("first_package"), "/launch", "/publisher.launch.py"]))

    subscriber = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [FindPackageShare("first_package"), "/launch", "/subscriber.launch.py"]))

    ld.add_action(publisher)
    ld.add_action(subscriber)
    return ld
