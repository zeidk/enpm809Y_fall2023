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
  double speed_{0};

 public:
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  MobileRobot() : MobileRobot(0, 0, 0) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */

  MobileRobot(double orientation) : MobileRobot(0, 0, orientation) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  MobileRobot(double x, double y) : MobileRobot(x, y, 0) {}

  /**
   * @brief Construct a new Mobile Robot object
   * @note This is a delegating constructor
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(double x, double y, double orientation)
      : position_{x, y}, orientation_{orientation} {}

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

  // ==================== operator overloading ====================
  MobileRobot operator+(const MobileRobot& other) const {
    // other.position_.first = 4;
    // this->position_.first = 3;

    auto x = this->position_.first + other.position_.first;
    auto y = this->position_.second + other.position_.second;
    double orientation = this->orientation_ + other.orientation_;
    return MobileRobot(x, y, orientation);  // constructor
  }
  
  // ==================== friend functions ====================
  friend std::ostream& operator<<(std::ostream& os, const MobileRobot& robot);
  friend std::istream& operator>>(std::istream& is, MobileRobot& robot);
};  // class MobileRobot
}  // namespace MazeNavigation
