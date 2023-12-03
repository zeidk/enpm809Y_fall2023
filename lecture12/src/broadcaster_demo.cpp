#include <broadcaster_demo.hpp>
#include "geometry_msgs/msg/transform_stamped.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <utils.hpp>
// needed for the listener
#include <tf2/exceptions.h>

// allows to use, 50ms, etc
using namespace std::chrono_literals;

void BroadcasterDemo::static_broadcast_timer_cb_()
{
    geometry_msgs::msg::TransformStamped static_transform_stamped;
    /////////////////////////////////////////////////
    // First frame
    /////////////////////////////////////////////////
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "odom";
    static_transform_stamped.child_frame_id = "first_static_frame";

    static_transform_stamped.transform.translation.x = 3.5;
    static_transform_stamped.transform.translation.y = 4.0;
    static_transform_stamped.transform.translation.z = 5.0;

    geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 2, M_PI / 3, M_PI / 4);
    static_transform_stamped.transform.rotation.x = quaternion.x;
    static_transform_stamped.transform.rotation.y = quaternion.y;
    static_transform_stamped.transform.rotation.z = quaternion.z;
    static_transform_stamped.transform.rotation.w = quaternion.w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Second frame
    /////////////////////////////////////////////////
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "odom";
    static_transform_stamped.child_frame_id = "second_static_frame";

    static_transform_stamped.transform.translation.x = 1.5;
    static_transform_stamped.transform.translation.y = 2.0;
    static_transform_stamped.transform.translation.z = 3.0;

    quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 5, M_PI / 5, M_PI / 5);
    static_transform_stamped.transform.rotation.x = quaternion.x;
    static_transform_stamped.transform.rotation.y = quaternion.y;
    static_transform_stamped.transform.rotation.z = quaternion.z;
    static_transform_stamped.transform.rotation.w = quaternion.w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);
}

void BroadcasterDemo::broadcast_timer_cb_()
{
    geometry_msgs::msg::TransformStamped dynamic_transform_stamped;

    // RCLCPP_INFO(this->get_logger(), "Broadcasting dynamic_frame");
    dynamic_transform_stamped.header.stamp = this->get_clock()->now();
    dynamic_transform_stamped.header.frame_id = "camera_rgb_optical_frame";
    dynamic_transform_stamped.child_frame_id = "cube";

    dynamic_transform_stamped.transform.translation.x = 1.0;
    dynamic_transform_stamped.transform.translation.y = 0.0;
    dynamic_transform_stamped.transform.translation.z = -0.2;

    geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI, 0.0, M_PI / 3);
    dynamic_transform_stamped.transform.rotation.x = quaternion.x;
    dynamic_transform_stamped.transform.rotation.y = quaternion.y;
    dynamic_transform_stamped.transform.rotation.z = quaternion.z;
    dynamic_transform_stamped.transform.rotation.w = quaternion.w;
    // Send the transform
    tf_broadcaster_->sendTransform(dynamic_transform_stamped);
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<BroadcasterDemo>("broadcaster_demo");
  rclcpp::spin(node);
  rclcpp::shutdown();
}