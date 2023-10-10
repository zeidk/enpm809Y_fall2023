#include <iostream>
#include "mobile_robot.h"

void MazeNavigation::MobileRobot::charge()
{
    std::cout << "Charging..." << std::endl;
}
void MazeNavigation::MobileRobot::rotate(double angle)
{
    std::cout << "Rotating " << angle << " degrees" << std::endl;
}
void MazeNavigation::MobileRobot::move_forward(double distance)
{ 
    std::cout << "Moving forward " << distance << " m" << std::endl;
}