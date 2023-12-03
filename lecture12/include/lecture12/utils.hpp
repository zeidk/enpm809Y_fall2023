#pragma once

#include <cmath>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/quaternion.hpp>

// create a utility class
class Utils
{
public:
    Utils(){}
    ~Utils(){}

    /**
     * @brief Get the quaternion from euler object
     *
     * @param roll  roll angle in radians
     * @param pitch  pitch angle in radians
     * @param yaw  yaw angle in radians
     * @return geometry_msgs::msg::Quaternion  Quaternion from rpy
     */
    geometry_msgs::msg::Quaternion set_quaternion_from_euler(double roll, double pitch, double yaw);
    
    /**
     * @brief Get the euler from quaternion object
     *
     * @param quaternion
     * @param roll
     * @param pitch
     * @param yaw
     * @return array[roll, pitch, yaw]
     */
    std::array<double, 3> set_euler_from_quaternion(tf2::Quaternion quaternion);
};


