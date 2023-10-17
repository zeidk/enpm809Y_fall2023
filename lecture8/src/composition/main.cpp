#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "composition.h"

int main() {
  auto robot = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 0, 13);
  robot->move_forward(14);
}
// #include "demo_member_initialization.h"
// #include "demo_static_attribute.h"
// #include "demo_static_method.h"
// #include "demo_this.h"
// #include "mobile_robot.h"

// using namespace std::string_literals;

// void check_status(const MazeNavigation::MobileRobot& robot) {
//   auto position = robot.get_position();
//   std::cout << "battery level: " << robot.get_battery_level() << '\n';
//   std::cout << "orientation: " << robot.get_orientation() << '\n';
//   std::cout << "position: " << position.first << ", " << position.second
//             << '\n';
//   std::cout << "speed: " << robot.get_speed() << '\n';
// }
// // int main() {
// //   // auto robot1 = std::make_unique<MazeNavigation::MobileRobot>();
// //   // auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(45);
// //   // auto robot3 = std::make_unique<MazeNavigation::MobileRobot>(2, 3);
// //   // auto robot4 = std::make_unique<MazeNavigation::MobileRobot>(4, 5,
// 90);

// //   // check_status(12.4);
// //   // MazeNavigation::MobileRobot robot();
// //   // MazeNavigation::MobileRobot robot1;
// //   // MazeNavigation::MobileRobot robot2(1, 2);
// //   // std::cout << robot1.get_speed() << '\n';
// //   // robot1.set_speed(10);
// //   // robot1.rotate(90);

// //   // auto robot2 = std::make_unique<MazeNavigation::MobileRobot>();
// //   // std::cout << "Address of position_: " << &(robot2->position_) <<
// '\n';
// //   // std::cout << "Address of orientation_: " << &(robot2->orientation_)
// <<
// //   // '\n'; std::cout << "Address of speed_: " << &(robot2->speed_) <<
// '\n';
// //   // std::cout << "Address of battery_level_: " <<
// &(robot2->battery_level_)
// //   <<
// //   // '\n';

// //   // (*robot2).rotate(90);
// //   // robot2->rotate(90);
// //   // std::cout << (*robot2).speed_ << '\n';
// //   // std::cout << robot2->speed_ << '\n';

// //   // this pointer
// //   DemoThis d;
// //   d.initialize(5).double_value().print_value();  // chaining function
// calls
// // }

// // static attribute
// // int Counter::count = 0;  // initialization of static member variable

// // int main() {
// //   Counter c1;
// //   std::cout << "Initial count: " << c1.get_count() << '\n';

// //   Counter c2, c3;
// //   std::cout << "After creating three objects: " << c2.get_count() << '\n';
// //   std::cout << "After creating three objects: " << c3.get_count() << '\n';
// // }

// // // static method
// // int DemoStaticMethod::count = 0;  // Initialize static member variable

// // int main() {
// //   std::cout << "Initial count: " << DemoStaticMethod::get_count() << '\n';

// //   DemoStaticMethod d1, d2, d3;
// //   std::cout << "After creating 3 objects: " <<
// DemoStaticMethod::get_count() << '\n';
// // }

// int main(){
//   auto robot1 = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 90);
//   auto robot2 = std::make_unique<MazeNavigation::MobileRobot>(1, 2, 90);
//   auto robot3 = (*robot1) + (*robot2);
//   std::cout << robot3 << '\n';

//   std::unique_ptr<MazeNavigation::MobileRobot> robot4(
//       new MazeNavigation::MobileRobot((*robot1) + (*robot2)));

//   std::cout << *robot4 << '\n';
//   // std::cout << *robot << "\n-------------------\n";
//   // auto robot2 = std::make_unique<MazeNavigation::MobileRobot>();
//   // auto robot3 = std::make_unique<MazeNavigation::MobileRobot>();
//   // std::cin >> *robot2 >> *robot3;
//   // std::cout << *robot2 << '\n';
//   // std::cout << "-------------------\n";
//   // std::cout << *robot3 << '\n';
//   // A a;
//   // a.display_robot(*robot);
//   // print_robot(*robot);
//   // robot->add_sensor("3D LIDAR"s);
//   // robot->add_sensor("2D LIDAR"s);
// }