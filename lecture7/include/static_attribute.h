#pragma once
#include <iostream>

class Counter {
 public:
  static int count;  // Declaration of static member variable
  Counter() { count++; }

  int get_count() {  // Static member function
    return count;
  }
};  // class Counter
