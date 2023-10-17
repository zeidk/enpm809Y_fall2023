#include <memory>

#include "explicit_keyword.h"

void check_orientation(const MazeNavigation::MobileRobot& robot) {
  std::cout << "orientation: " << robot.get_orientation() << '\n';
}

int main() {
  check_orientation(12.4);  // call 1-arg constructor
}

