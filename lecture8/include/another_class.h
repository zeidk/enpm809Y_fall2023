#pragma once

#include "friend_class.h"

namespace MazeNavigation {
class MobileRobot;
}

class AnotherClass {
    public:
        void print_robot(const MazeNavigation::MobileRobot& robot);
};