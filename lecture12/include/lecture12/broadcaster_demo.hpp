#pragma once

#include <cmath>
#include <tf2_ros/static_transform_broadcaster.h>
#include <utils.hpp>
#include <geometry_msgs/msg/pose.hpp>
// for static broadcaster
#include "tf2_ros/static_transform_broadcaster.h"
// for dynamic broadcaster
#include "tf2_ros/transform_broadcaster.h"
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
using namespace std::chrono_literals;

class BroadcasterDemo : public rclcpp::Node
{
public:
    BroadcasterDemo(std::string node_name) : Node(node_name)
    {
        // parameter to decide whether to execute the broadcaster or not
        RCLCPP_INFO(this->get_logger(), "Broadcaster demo started");

        // initialize a static transform broadcaster
        tf_static_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

        // initialize the transform broadcaster
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        // Load a buffer of transforms
        tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tf_buffer_->setUsingDedicatedThread(true);
        // Create a utils object to use the utility functions
        utils_ptr_ = std::make_shared<Utils>();

        // timer to publish the transform
        broadcast_timer_ = this->create_wall_timer(
            100ms,
            std::bind(&BroadcasterDemo::broadcast_timer_cb_, this));

        // timer to publish the transform
        static_broadcast_timer_ = this->create_wall_timer(
            10s,
            std::bind(&BroadcasterDemo::static_broadcast_timer_cb_, this));

    }


private:
    /*!< Boolean parameter to whether or not start the broadcaster */
    bool param_broadcast_;
    /*!< Buffer that stores several seconds of transforms for easy lookup by the listener. */
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    /*!< Static broadcaster object */
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> tf_static_broadcaster_;
    /*!< Broadcaster object */
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    /*!< Utils object to access utility functions*/
    std::shared_ptr<Utils> utils_ptr_;
    /*!< Wall timer object for the broadcaster*/
    rclcpp::TimerBase::SharedPtr broadcast_timer_;
    /*!< Wall timer object for the static broadcaster*/
    rclcpp::TimerBase::SharedPtr static_broadcast_timer_;

    /**
     * @brief Timer to broadcast the transform
     *
     */
    void broadcast_timer_cb_();
    /**
     * @brief Timer to broadcast the transform
     *
     */
    void static_broadcast_timer_cb_();
};
