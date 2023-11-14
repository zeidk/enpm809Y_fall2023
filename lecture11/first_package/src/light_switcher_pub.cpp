
#include "light_switcher_pub.h"

#include <rclcpp/rclcpp.hpp>

void skynet::LightSwitcherPub::light_status_timer_cb() {
  std_msgs::msg::Bool message;
  message.data = light_status_;
  publisher_ = this->create_publisher<std_msgs::msg::Bool>("light_status", 10);
  publisher_->publish(message);
  RCLCPP_INFO_STREAM(this->get_logger(), "Published " << message.data);
  light_status_ = !light_status_;
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<skynet::LightSwitcherPub>("light_switcher_pub");
  rclcpp::spin(node);
  rclcpp::shutdown();
}