#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "battery.h"

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace MazeNavigation {
/**
 * @brief Class for the mobile robot
 *
 */
class MobileRobot {
 private:
  // ==================== attributes ====================
  //<! position of the robot
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  double orientation_;
  //<! speed of the robot
  double speed_{0};
  //<! battery of the robot
  MazeNavigation::Battery battery_;

 public:
  // ==================== constructors ====================
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot() : MobileRobot(0, 0, 0, 100) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  
  MobileRobot(double orientation) : MobileRobot(0, 0, orientation, 100) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(double x, double y) : MobileRobot(x, y, 0, 100) {}
  /**
   * @brief Construct a new Mobile Robot object
   * @note This is a delegating constructor
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  MobileRobot(double x, double y, double orientation)
      : MobileRobot(x, y, orientation, 100) {}
  /**
   * @brief Construct a new Mobile Robot object
   * @note This is a delegating constructor
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(double x, double y, double orientation, double battery_charge)
      : position_{x, y},
        orientation_{orientation},
        battery_{100, battery_charge, 12, false} {}

  // ==================== accessors ====================
  /**
   * @brief Get the position of the robot
   *
   * @return std::pair<double, double>
   */
  std::pair<double, double> get_position() const { return position_; }
  /**
   * @brief Get the orientation of the robot
   *
   * @return double
   */
  double get_orientation() const { return orientation_; }
  /**
   * @brief Get the speed of the robot
   *
   * @return double
   */
  double get_speed() const { return speed_; }

  /**
   * @brief Get the battery level of the robot
   *
   * @return double
   */
  double get_battery_level() const { return battery_.get_current_charge(); }

  // ==================== methods ====================
  /**
   * @brief Move the robot forward by a given distance
   *
   * @param distance distance to move
   */
  void move_forward(double distance);
  /**
   * @brief Move the robot backward by a given distance
   *
   * @param distance distance to move
   */
  void move_backward(double distance);
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle angle to rotate (in degrees)
   */
  void rotate(double angle);
  /**
   * @brief Charge the robot's battery
   *
   * This method calls the Battery::start_charging() method
   *
   */
  void charge_battery();

};  // class MobileRobot
}  // namespace MazeNavigation
