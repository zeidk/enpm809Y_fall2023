#include <chrono>
#include <iostream>
#include <thread>

#include "aggregation/aggregation.h"

void MazeNavigation::MobileRobot::add_sensor(
    std::unique_ptr<MazeNavigation::Sensor> sensor) {
  sensors_.push_back(std::move(sensor));
}

double MazeNavigation::MobileRobot::get_sensor_reading(int period) const{
  for (const auto& sensor : sensors_) {
    sensor->start_reading(period);
  }
  double sensor_reading{0.0};
  for (const auto& sensor : sensors_) {
    sensor_reading += sensor->get_sensor_data();
  }
  return sensor_reading;
}

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