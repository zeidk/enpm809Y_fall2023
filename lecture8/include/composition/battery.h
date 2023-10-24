#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace MazeNavigation {
/**
 * @brief Class for the battery
 *
 */
class Battery {
 private:
  // ==================== attributes ====================
  /*< Capacity*/
  double capacity_;
  double current_charge_;
  double voltage_;
  bool is_charging_;

 public:
  // ==================== constructors ====================
  Battery(double capacity, double current_charge, double voltage, bool is_charging)
      : capacity_{capacity},
        current_charge_{current_charge},
        voltage_{voltage},
        is_charging_{is_charging} {}

  // ==================== accessors ====================
  /**
   * @brief Get the capacity of the battery
   *
   * @return double
   */
  double get_current_charge() const { return current_charge_; }

  // ==================== methods ====================
  /**
   * @brief Start charging the battery
   *
   */
  void start_charging();
  /**
   * @brief Stop charging the battery
   *
   */
  void stop_charging();
  /**
   * @brief Discharge the battery
   *
   * Each time the robot moves, the battery discharges by 1 percent
   */
  void discharge(double decrement);

};  // class Battery
}  // namespace MazeNavigation
