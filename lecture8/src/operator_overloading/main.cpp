#include <memory>

#include "operator_overloading/operator_overloading.h"

int main() {
  // auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0);
  // auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 35);
  // std::cout << (*robot) << (*robot2)  << '\n';

  // robot + robot2;

    auto robot1 = std::make_unique<MazeNavigation::MobileRobot>(1,1);
    // auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(1,1);
    // std::cin >> (*robot1) >> (*robot2);

    std::cout << *robot1 << '\n';
    // std::cout << *robot2;
}