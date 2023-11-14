
#include "first_package.h"

#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<skynet::FirstPackage>("hello");
  rclcpp::spin(node);
  rclcpp::shutdown();
}