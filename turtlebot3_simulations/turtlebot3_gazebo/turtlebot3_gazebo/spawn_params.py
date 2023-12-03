#!/usr/bin/env python3

import os

import xml.etree.ElementTree as ET
from turtlebot3_gazebo.utilities import pose_info
from ament_index_python.packages import get_package_share_directory


class SpawnParams:
    '''
    Class to spawn parts
    '''

    def __init__(self, name, file_path=None, xyz=[0, 0, 0], rpy=[0, 0, 0], ns='', rf=''):
        '''
        init function
        '''
        self.name = name
        self.xml = ""
        self.file_path = file_path
        self.initial_pose = pose_info(xyz, rpy)
        self.robot_namespace = ns
        self.reference_frame = rf

    def get_sdf(self, file_path: str) -> str:
        '''
        Get the sdf file of the part

        Args:
            file_path (str): Path to the sdf file
        '''
        try:
            f = open(file_path, 'r')
            entity_xml = f.read()
        except IOError:
            return ''

        return entity_xml


class PartSpawnParams(SpawnParams):
    part_types = ['battery', 'pump', 'sensor', 'regulator']

    colors = {
        'blue': (0, 0, 168),
        'green': (0, 100, 0),
        'red': (139, 0, 0),
        'purple': (138, 0, 226),
        'orange': (255, 140, 0)
    }

    def __init__(self, name, part_type, color, xyz=[0, 0, 0], rpy=[0, 0, 0], rf=''):
        file_path = os.path.join(get_package_share_directory('turtlebot3_gazebo'),
                                 'models', part_type, 'model.sdf')

        super().__init__(name=name, file_path=file_path, xyz=xyz, rpy=rpy, rf=rf)

        self.part_type = part_type
        self.color = color

        self.modify_xml()

    def modify_xml(self):
        xml = ET.fromstring(self.get_sdf(self.file_path))

        r, g, b = self.colors[self.color]
        color_string = str(r/255) + " " + str(g/255) + " " + str(b/255) + " 1"

        for elem in xml.find('model').find('link').findall('visual'):
            if elem.attrib['name'] == "base":
                elem.find("material").find("ambient").text = color_string
                elem.find("material").find("diffuse").text = color_string

        self.xml = ET.tostring(xml, encoding="unicode")
