#pragma once
#include <iostream>

class DemoStaticMethod {
 public:
  static int count;
  DemoStaticMethod() { count++; }

  static int get_count() {  // Static method
    return count;
  }
};
