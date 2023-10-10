#include <iostream>
#include <memory>
#include "mobile_robot.h"

int main(){
    MazeNavigation::MobileRobot robot1;
    robot1.rotate(90);
    std::cout << robot1.speed_ << '\n';

    auto robot2 = std::make_unique<MazeNavigation::MobileRobot>();
    (*robot2).rotate(90);
    robot2->rotate(90);
    std::cout << (*robot2).speed_ << '\n';
    std::cout << robot2->speed_ << '\n';
}