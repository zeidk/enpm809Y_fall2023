#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>

namespace demo {
class LightSwitcherPub : public rclcpp::Node {
 public:
  LightSwitcherPub(std::string node_name) : Node(node_name) {
    publisher_ = this->create_publisher<std_msgs::msg::Bool>("light_status", 10);

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&LightSwitcherPub::light_status_timer_cb, this));
   }

  private:
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    void light_status_timer_cb();
    bool light_status_ = false;
};  // class LightSwitcherPub
}  // namespace demo