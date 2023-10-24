#pragma once

#include <iostream>
#include <utility>

namespace RWA2 {
class MobileRobot final{
 public:
  MobileRobot(double x, double y, double orientation)
      : position_{x, y}, orientation_{orientation} {
    /*empty body*/
  }

  void rotate(double angle);
  void move();
  void print_status();

 protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};

};  // class MobileRobot
}  // namespace RWA2