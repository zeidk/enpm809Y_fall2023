#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>

namespace skynet {
class LightSwitcherSub : public rclcpp::Node {
 public:
  LightSwitcherSub(std::string node_name) : Node(node_name) {
    subscription_ = this->create_subscription<std_msgs::msg::Bool>("light_status", 
    10, std::bind(&LightSwitcherSub::light_status_sub_cb, this, std::placeholders::_1));
  }
  private: 
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscription_;
    void light_status_sub_cb(const std_msgs::msg::Bool::SharedPtr msg);
};  // class FirstPackage
}  // namespace skynet