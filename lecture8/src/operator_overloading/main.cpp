#include <memory>

#include "operator_overloading.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0);
  std::cout << (*robot) << '\n';

//   auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 35);
//   auto robot3 = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 35);
//   auto robot4 = (*robot2) + (*robot3);
//   std::cout << robot4 << '\n';
}