#include <utils.hpp>

geometry_msgs::msg::Quaternion Utils::set_quaternion_from_euler(double roll, double pitch, double yaw)
{
    tf2::Quaternion q;
    geometry_msgs::msg::Quaternion q_msg;

    q.setRPY(roll, pitch, yaw);

    q_msg.x = q.x();
    q_msg.y = q.y();
    q_msg.z = q.z();
    q_msg.w = q.w();

    return q_msg;
}

std::array<double, 3> Utils::set_euler_from_quaternion(tf2::Quaternion quaternion)
{
    double roll;
    double pitch;
    double yaw;
    tf2::Matrix3x3 matrix(quaternion);
    matrix.getRPY(roll, pitch, yaw);
    // create an empty array of doubles to store the roll, pitch, yaw
    std::array<double, 3> rpy;
    rpy.at(0) = roll;
    rpy.at(1) = pitch;
    rpy.at(2) = yaw;

    return rpy;
}