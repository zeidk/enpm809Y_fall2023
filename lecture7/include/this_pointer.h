#pragma once
#include <iostream>

class DemoThis {
 private:
  int number_;

 public:
  // Using 'this' to differentiate member variable from parameter name.
  void set_number(int number) { this->number_ = number; }
  int get_number() { return this->number_; }

  // Chain member function calls using 'this'
  DemoThis& initialize(int val) {
    this->number_ = val;
    return *this;
  }

  DemoThis& double_value() {
    this->number_ *= 2;
    return *this;
  }

  void print_value() { 
    std::cout << "Number: " << this->number_ << '\n'; 
    }
};


