#include "another_class.h"

void AnotherClass::print_robot(const MazeNavigation::MobileRobot& robot){
    std::cout << "Position: " << robot.position_.first << ", "
              << robot.position_.second << '\n';
    std::cout << "Orientation: " << robot.orientation_ << '\n';
    std::cout << "Speed: " << robot.speed_ << '\n';
}