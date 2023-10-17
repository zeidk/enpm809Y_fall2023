#pragma once

#include <iostream>

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
  // Attributes
  //<! position of the robot
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  double orientation_;
  //<! speed of the robot
  double speed_;
  //<! battery level of the robot
  double battery_level_;

 public:
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   */
  MobileRobot() {
    position_ = std::make_pair(0, 0);
    orientation_ = 0;
    speed_ = 0;
    battery_level_ = 100;
  }

  // ==================== accessors ====================
  /**
   * @brief Get the position of the robot
   *
   * @return std::pair<double, double> position
   */
  std::pair<double, double> get_position() const { return position_; }
  /**
   * @brief Get the orientation of the robot
   *
   * @return double orientation (in rad)
   */
  double get_orientation() const { return orientation_; }
  /**
   * @brief Get the speed of the robot
   *
   * @return double speed
   */
  double get_speed() const { return speed_; }

  /**
   * @brief Get the battery level of the robot
   *
   * @return double battery level
   */
  double get_battery_level() const { return battery_level_; }

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

};  // class MobileRobot
}  // namespace MazeNavigation
