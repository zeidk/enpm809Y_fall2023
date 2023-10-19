#pragma once
#include <iostream>

class DemoStaticAttribute {
 public:
  static int count;  // Declaration of static member variable
  DemoStaticAttribute() { count++; }

  int get_count() {  // Static member function
    return count;
  }
};  // class Counter
