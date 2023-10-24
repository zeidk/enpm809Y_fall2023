#include "composition/composition.h"

#include <chrono>
#include <iostream>
#include <thread>


//==============================================================================
void MazeNavigation::MobileRobot::charge_battery() {
  battery_.start_charging();
}
//==============================================================================

void MazeNavigation::MobileRobot::rotate(double angle) {
  std::cout << "Rotating " << angle << " degrees" << '\n';
}
//==============================================================================

void MazeNavigation::MobileRobot::move_forward(double distance) {
  // each meter consumes 1% of the battery
  // check if the battery has enough charge to move the robot forward by the
  // given distance
  if (battery_.get_current_charge() < distance) {
    std::cout << "Battery level is too low to move forward by " << distance
              << " m\n";
    charge_battery();
  }
  
  std::cout << "Moving forward " << distance << " m\n";
  std::chrono::seconds duration(static_cast<int>(distance));
  std::this_thread::sleep_for(duration);
  std::cout << "Robot moved forward " << distance << " m\n";
  battery_.discharge(distance);
}
//==============================================================================

void MazeNavigation::MobileRobot::move_backward(double distance) {
  // each meter consumes 1% of the battery
  // check if the battery has enough charge to move the robot backward by the
  // given distance
  if (battery_.get_current_charge() < distance) {
    std::cout << "Battery level is too low to move backward by " << distance
              << " m\n";
    charge_battery();
  }
  std::cout << "Moving backward " << distance << " m\n";
  std::chrono::seconds duration(static_cast<int>(distance));
  std::this_thread::sleep_for(duration);
  std::cout << "Robot moved forward " << distance << " m\n";
  battery_.discharge(distance);
}
