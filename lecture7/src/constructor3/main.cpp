#include <iostream>
#include <memory>

#include "constructor3.h"

int main() {
  auto robot1 = std::make_unique<MazeNavigation::MobileRobot>();
  std::cout << robot1->get_battery_level() << '\n';
  std::cout << robot1->get_speed() << '\n';
  std::cout << robot1->get_orientation() << '\n';
  std::cout << robot1->get_position().first << '\n';
  std::cout << robot1->get_position().second << '\n';

  std::cout << "=========================" << '\n';

  auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(1, 1, 34);
  std::cout << robot2->get_battery_level() << '\n';
  std::cout << robot2->get_speed() << '\n';
  std::cout << robot2->get_orientation() << '\n';
  std::cout << robot2->get_position().first << '\n';
  std::cout << robot2->get_position().second << '\n';
}