#include "friend_class/friend_class.h"

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