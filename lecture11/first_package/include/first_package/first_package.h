#pragma once

#include <rclcpp/rclcpp.hpp>

namespace skynet{
class FirstPackage : public rclcpp::Node {
    public:
    FirstPackage(std::string node_name): Node(node_name){
      RCLCPP_INFO(this->get_logger(), "Hello");
    }

}; // class FirstPackage
} // namespace skynet