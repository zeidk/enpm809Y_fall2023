#include "friend_function/friend_function.h"

//==============================================================================
void print_robot(const MazeNavigation::MobileRobot& robot) {
  std::cout << "Position: " << robot.position_.first << ", "
            << robot.position_.second << '\n';
  std::cout << "Orientation: " << robot.orientation_ << '\n';
  std::cout << "Speed: " << robot.speed_ << '\n';
}

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