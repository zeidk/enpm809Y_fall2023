#pragma once

#include <rclcpp/rclcpp.hpp>

#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

namespace navigation {
class NavigationDemo : public rclcpp::Node {
 public:
  using NavigateToPose = nav2_msgs::action::NavigateToPose;
  using GoalHandleNavigation = rclcpp_action::ClientGoalHandle<NavigateToPose>;
  NavigationDemo(std::string node_name) : Node(node_name) {
    // initialize the client
    client_ =
        rclcpp_action::create_client<NavigateToPose>(this, "navigate_to_pose");
    // initialize the publisher
    initial_pose_pub_ =
        this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
            "initialpose", 10);

    // set the initial pose for navigation
    set_initial_pose();
    // pause for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    // send the goal
    send_goal();
  }

 private:
  /**
   * @brief Publisher to the topic /initialpose
   *
   */
  rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
      initial_pose_pub_;
  /**
   * @brief Action client for the action server navigate_to_pose
   *
   */
  rclcpp_action::Client<NavigateToPose>::SharedPtr client_;
  //   rclcpp::TimerBase::SharedPtr timer_;
  /**
   * @brief Response from the server after sending the goal
   */
  void goal_response_callback(
      std::shared_future<GoalHandleNavigation::SharedPtr> future);
  /**
   * @brief Feedback received while the robot is driving towards the goal
   *
   * @param feedback
   */
  void feedback_callback(
      GoalHandleNavigation::SharedPtr,
      const std::shared_ptr<const NavigateToPose::Feedback> feedback);
  /**
   * @brief Result after the action has completed
   *
   * @param result
   */
  void result_callback(const GoalHandleNavigation::WrappedResult& result);
  /**
   * @brief Method to build and send a goal using the client
   *
   */
  void send_goal();
  void set_initial_pose();
};  // class NavigationDemo
}  // namespace navigation