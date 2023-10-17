#include <memory>

#include "delegating_constructor.h"

int main() {
  auto robot1 = std::make_unique<MazeNavigation::MobileRobot>();
  auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(45);
  auto robot3 = std::make_unique<MazeNavigation::MobileRobot>(1, 1);
  auto robot4 = std::make_unique<MazeNavigation::MobileRobot>(1, 1, 34);
}