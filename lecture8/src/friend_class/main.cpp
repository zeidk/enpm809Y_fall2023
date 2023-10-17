#include <memory>

#include "friend_class.h"
#include "another_class.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0);
  AnotherClass another_class;
  another_class.print_robot(*robot);
}