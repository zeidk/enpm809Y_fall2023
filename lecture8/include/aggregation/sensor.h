#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace MazeNavigation {
/**
 * @brief Class for the sensor
 *
 */
class Sensor {
 private:
  // ==================== attributes ====================
  std::string sensor_name_;
  double sensor_data_{0.0};

 public:
  // ==================== constructors ====================
  Sensor(std::string sensor_name) : sensor_name_{sensor_name} {}

  // ==================== methods ====================
  /**
   * @brief Update the sensor data
   *
   */
  void update_data();
  /**
   * @brief Start reading the sensor data
   *
   * @param period Period of the reading (in s)
   */
  void start_reading(unsigned int period);
  /**
   * @brief Stop reading the sensor data
   *
   */
  void stop_reading();
  /**
   * @brief Get the sensor data
   *
   * @return double
   */
  double get_sensor_data();
};  // class Sensor
}  // namespace MazeNavigation
