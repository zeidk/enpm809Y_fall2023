#include <memory>
#include "friend_function.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0);
  print_robot(*robot);
}