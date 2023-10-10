#pragma once
#include <utility>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace MazeNavigation
{
/**
 * @brief Class for the mobile robot
 *
 */
class MobileRobot
{
 public:
  std::pair<double, double> position_;
  double orientation_;
  double speed_;
  double battery_level_;

  /**
   * @brief Move the robot forward by a given distance
   *
   * @param distance
   */
  void move_forward(double distance);
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle
   */
  void rotate(double angle);
  /**
   * @brief Charge the robot
   *
   */
  void charge();
};
}  // namespace MazeNavigation