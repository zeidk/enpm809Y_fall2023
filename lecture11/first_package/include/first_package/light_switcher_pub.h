#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>

namespace skynet {
class LightSwitcherPub : public rclcpp::Node {
 public:
  LightSwitcherPub(std::string node_name) : Node(node_name) {
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&LightSwitcherPub::light_status_timer_cb, this));
    
  }

  private:
   rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_;
   void light_status_timer_cb();
   rclcpp::TimerBase::SharedPtr timer_;
   bool light_status_ = true;

};  // class FirstPackage
}  // namespace skynet