#pragma once

#include <cmath>
#include <utils.hpp>
#include <geometry_msgs/msg/pose.hpp>
// needed for the listener
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

// allows to use, 50ms, etc
using namespace std::chrono_literals;

class ListenerDemo : public rclcpp::Node
{
public:
    ListenerDemo(std::string node_name) : Node(node_name)
    {
        // parameter to decide whether to execute the demo or not
        // this->declare_parameter("listen", false);
        // param_listen_ = this->get_parameter("listen").as_bool();

        // // do not execute the demo if the parameter is false
        // if (!param_listen_)
        // {
        //     RCLCPP_WARN(this->get_logger(), "Listener demo not started");
        //     return;
        // }

        RCLCPP_INFO(this->get_logger(), "Listener demo started");

        // load a buffer of transforms
        tf_buffer_ =
            std::make_unique<tf2_ros::Buffer>(this->get_clock());
        transform_listener_ =
            std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        // timer to listen to the transforms
        listen_timer_ = this->create_wall_timer(1s, std::bind(&ListenerDemo::listen_timer_cb_, this));
    }

private:
    /*!< Boolean variable to store the value of the parameter "listen" */
    bool param_listen_;
    /*!< Buffer that stores several seconds of transforms for easy lookup by the listener. */
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    /*!< Transform listener object */
    std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
    /*!< Wall timer object */
    rclcpp::TimerBase::SharedPtr listen_timer_;

    /**
     * @brief Listen to a transform
     *
     * @param source_frame Source frame (child frame) of the transform
     * @param target_frame Target frame (parent frame) of the transform
     */
    void listen_transform(const std::string &source_frame, const std::string &target_frame);

    /**
     * @brief Timer to listen to the transform
     *
     */
    void listen_timer_cb_();
};
