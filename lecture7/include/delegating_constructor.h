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
  //==========================attributes==========================
  //<! position of the robot
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  double orientation_;
  //<! speed of the robot
  double speed_{0.0};
  //<! battery level of the robot
  double battery_level_{100.0};

 public:
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   */
  MobileRobot() : position_{std::make_pair(0, 0)}, orientation_{0} {
    std::cout << "default constructor" << '\n';
  }

  /**
   * @brief Construct a new Mobile Robot object
   *
   * @param orientation orientation of the robot (in rad)
   */
  MobileRobot(double orientation)
      : position_{std::make_pair(0, 0)}, orientation_{orientation} {
    std::cout << "1-arg constructor" << '\n';
  }

  /**
   * @brief Construct a new Mobile Robot object
   *
   * @param x x coordinate
   * @param y y coordinate
   */
  MobileRobot(double x, double y)
      : position_{std::make_pair(x, y)}, orientation_{0.0} {
    std::cout << "2-arg constructor" << '\n';
  }

  /**
   * @brief Construct a new Mobile Robot object
   *
   * @param x x coordinate
   * @param y y coordinate
   * @param orientation orientation of the robot (in rad)
   */
  MobileRobot(double x, double y, double orientation)
      : position_{std::make_pair(x, y)}, orientation_{orientation} {
    std::cout << "3-arg constructor" << '\n';
  }

  //==========================delegating constructor==========================
  // /**
  //  * @brief Construct a new Mobile Robot object
  //  * - first argument: x position
  //  * - second argument: y position
  //  */
  // ~MobileRobot() { std::cout << "destructor" << '\n'; }

  // MobileRobot() : MobileRobot(0, 0, 0) {
  //   std::cout << "default constructor" << '\n';
  // }

  // /**
  //  * @brief Construct a new Mobile Robot object
  //  *
  //  * @param orientation orientation of the robot (in rad)
  //  */
  // MobileRobot(double orientation) : MobileRobot(0, 0, orientation) {
  //   std::cout << "1-arg constructor" << '\n';
  // }

  // /**
  //  * @brief Construct a new Mobile Robot object
  //  *
  //  * @param x x coordinate
  //  * @param y y coordinate
  //  */
  // MobileRobot(double x, double y) : MobileRobot(x, y, 0) {
  //   std::cout << "2-arg constructor" << '\n';
  // }

  // /**
  //  * @brief Construct a new Mobile Robot object
  //  * @note This constructor is the only one that does not delegate to another
  //  * @param x x coordinate
  //  * @param y y coordinate
  //  * @param orientation orientation of the robot (in rad)
  //  */
  // MobileRobot(double x, double y, double orientation)
  //     : position_{std::make_pair(x, y)}, orientation_{orientation} {
  //   std::cout << "delegated constructor" << '\n';
  // }

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
