#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "composition/composition.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0, 15);
  robot->move_forward(14);
}
