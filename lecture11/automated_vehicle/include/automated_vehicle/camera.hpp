#pragma once
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <string>

namespace automated_vehicle
{
class Camera : public rclcpp::Node
{
public:
  Camera(std::string node_name) : Node(node_name)
  {
    camera_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
    camera_timer_ =
        this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&Camera::camera_pub_data_cb, this));
  }

private: 

rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr camera_publisher_;
void camera_pub_data_cb();

rclcpp::TimerBase::SharedPtr camera_timer_;

};  // class AutomatedVehicle
}  // namespace automated_vehicle