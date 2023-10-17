#include <iostream>
#include <memory>

#include "constructor2.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>();
  std::cout << robot->get_battery_level() << '\n';
  std::cout << robot->get_speed() << '\n';
  std::cout << robot->get_orientation() << '\n';
  std::cout << robot->get_position().first << '\n';
  std::cout << robot->get_position().second << '\n';
}