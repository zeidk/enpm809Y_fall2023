#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "aggregation.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0);
  robot->add_sensor(std::make_unique<MazeNavigation::Sensor>("2D lidar"));
  robot->add_sensor(std::make_unique<MazeNavigation::Sensor>("3D lidar"));

    std::cout << robot->get_sensor_reading(5) << '\n';
}