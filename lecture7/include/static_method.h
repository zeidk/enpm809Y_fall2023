#pragma once
#include <iostream>

class DemoStaticMethod {
 private:
  int x;

 public:
  static int count;
  DemoStaticMethod() { count++; }

  static int get_count() {  // Static method
  // std::cout << x << '\n'; // error: x is not static
    return count;
  }
};
