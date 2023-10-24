#include "operator_overloading/operator_overloading.h"

#include <iostream>

//==============================================================================
namespace MazeNavigation {
std::ostream& operator<<(std::ostream& os, const MobileRobot& robot) {
  os << "Position: (" << robot.position_.first << "," << robot.position_.second
     << ")"
     << "\nOrientation: " << robot.orientation_ ;
  return os;
}
}  // namespace MazeNavigation


//==============================================================================
void MazeNavigation::MobileRobot::rotate(double angle) {
  std::cout << "Rotating " << angle << " degrees" << '\n';
}

//==============================================================================
void MazeNavigation::MobileRobot::move_forward(double distance) {
  std::cout << "Moving forward " << distance << " m\n";
}

//==============================================================================
void MazeNavigation::MobileRobot::move_backward(double distance) {
  std::cout << "Moving backward " << distance << " m\n";
}