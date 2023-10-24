#include <iostream>
#include <memory>
#include <vector>

// #include "inheritance/base_derived.h"
// #include "inheritance/mobile_robot.h"
#include "inheritance/constructors.h"

//==============================================================================
// int main() {
//   DerivedPublic derived_public;
//   DerivedProtected derived_protected;
//   DerivedPrivate derived_private;
// }

//==============================================================================
int main(){
  // Base base;
  Derived derived(10);
}

//==============================================================================
// Without polymorphism
//==============================================================================
// void get_status(const std::vector<std::unique_ptr<RWA2::AerialRobot>>& robots) {
//   for (const auto& robot : robots)
//     robot->print_status();
// }

// void get_status(const std::vector<std::unique_ptr<RWA2::LeggedRobot>>& robots) {
//   for (const auto& robot : robots)
//     robot->print_status();
// }

// void get_status(const std::vector<std::unique_ptr<RWA2::WheeledRobot>>& robots) {
//   for (const auto& robot : robots)
//     robot->print_status();
// }

// int main() {
//   std::vector<std::unique_ptr<RWA2::AerialRobot>> aerial_robots;
//   std::vector<std::unique_ptr<RWA2::LeggedRobot>> legged_robots;
//   std::vector<std::unique_ptr<RWA2::WheeledRobot>> wheeled_robots;

//   auto aerial_ptr =
//       std::make_unique<RWA2::AerialRobot>(2.5, 5.5, 45.0, false);

//   auto legged_ptr =
//       std::make_unique<RWA2::LeggedRobot>(3.5, 6.5, 45.0, 0.5);

//   auto wheeled_ptr =
//       std::make_unique<RWA2::WheeledRobot>(4.5, 7.5, 0.0, 6, 2);

//   aerial_robots.push_back(std::move(aerial_ptr));
//   legged_robots.push_back(std::move(legged_ptr));
//   wheeled_robots.push_back(std::move(wheeled_ptr));

//   get_status(aerial_robots);
//   get_status(legged_robots);
//   get_status(wheeled_robots);
// }

//==============================================================================
// With polymorphism (pointer version)
//==============================================================================
// void get_status(const std::vector<std::unique_ptr<RWA2::MobileRobot>>& robots) {
//   for (const auto& robot : robots)
//     robot->print_status();
// }

// int main() {
//   std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;

//   std::unique_ptr<RWA2::MobileRobot> aerial_ptr =
//       std::make_unique<RWA2::AerialRobot>(2.5, 5.5, 45.0, false);

//   std::unique_ptr<RWA2::MobileRobot> legged_ptr =
//       std::make_unique<RWA2::LeggedRobot>(3.5, 6.5, 45.0, 0.5);

//   std::unique_ptr<RWA2::MobileRobot> wheeled_ptr =
//       std::make_unique<RWA2::WheeledRobot>(4.5, 7.5, 0.0, 6, 2);

//   mobile_robots.push_back(std::move(aerial_ptr));
//   mobile_robots.push_back(std::move(legged_ptr));
//   mobile_robots.push_back(std::move(wheeled_ptr));

//   get_status(mobile_robots);
// }

//==============================================================================
// With polymorphism (reference version)
//==============================================================================
// void get_status(RWA2::MobileRobot& robot) {
//     robot.print_status();
// }

// int main() {
//   RWA2::MobileRobot mobile_robot(1.5, 4.5, 45.0);

//   std::vector<std::reference_wrapper<RWA2::MobileRobot>> mobile_robots;

//   RWA2::AerialRobot aerial_robot(2.5, 5.5, 45.0, false);
//   RWA2::MobileRobot& aerial_robot_ref{aerial_robot};

//   RWA2::LeggedRobot legged_robot(3.5, 6.5, 45.0, 0.5);
//   RWA2::MobileRobot& legged_robot_ref{legged_robot};

//   RWA2::WheeledRobot wheeled_robot(4.5, 7.5, 0.0, 6, 2);
//   RWA2::MobileRobot& wheeled_robot_ref{wheeled_robot};

//   mobile_robots.push_back(aerial_robot_ref);
//   mobile_robots.push_back(legged_robot_ref);
//   mobile_robots.push_back(wheeled_robot_ref);

//   for (const auto& robot : mobile_robots){
//     get_status(robot);
//   }
// }