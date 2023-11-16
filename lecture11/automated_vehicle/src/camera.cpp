#include "camera.hpp"

#include <sensor_msgs/msg/image.hpp>



void automated_vehicle::Camera::camera_pub_data_cb() {
  sensor_msgs::msg::Image msg;
  // fill out header data structure
  rclcpp::Time time_now{this->now()};
  msg.header.stamp.nanosec = static_cast<uint32_t>(time_now.nanoseconds());
  msg.header.stamp.sec = time_now.seconds();
  msg.header.frame_id = "camera_frame";

  // fill out other entries
  msg.height = 480;
  msg.width = 640;
  msg.encoding = "rgb8";
  msg.is_bigendian = false;

  msg.step = msg.width * 3;

  // generate msg.data, fill with random number
  int img_size{static_cast<int>(msg.height) * static_cast<int>(msg.step)};
  msg.data.reserve(img_size);
  srand(time(NULL));  // randomize seed
  for (int i{0}; i < img_size; i++) {
    msg.data.emplace_back(rand() % 256);
  }

  RCLCPP_INFO_STREAM(this->get_logger(), "frame: " << msg.header.frame_id);
  // publish
  camera_publisher_->publish(msg);
}

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<automated_vehicle::Camera>("camera");
  rclcpp::spin(node);
  rclcpp::shutdown();
}