#pragma once
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

namespace automated_vehicle {
class Camera : public rclcpp::Node {
 public:
  Camera(std::string node_name) : Node(node_name) {
  }

 private:

};  // class AutomatedVehicle
}  // namespace automated_vehicle