#include "battery.h"

#include <chrono>
#include <thread>

void MazeNavigation::Battery::start_charging() {
  std::cout << "Battery started charging" << '\n';
  is_charging_ = true;
  std::chrono::seconds duration(5);
  std::this_thread::sleep_for(duration);
  stop_charging();
  current_charge_ = capacity_;
}

void MazeNavigation::Battery::stop_charging() {
  is_charging_ = false;
  std::cout << "Battery finished charging" << '\n';
}

void MazeNavigation::Battery::discharge(double decrement) {
  current_charge_ -= decrement;
  std::cout << "Current charge: " << current_charge_ << '\n';
}