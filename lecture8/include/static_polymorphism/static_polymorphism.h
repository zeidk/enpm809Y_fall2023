#pragma once
#include <iostream>

class Base {
 public:
  // constructor
  Base(int value)
      : base_attribute_{value} {
    /*empty body*/
  }
  void greet() {
    std::cout << "Hello from Base\n";
  }

  void add(int value) {
    base_attribute_ += value;
  }

 protected:
  int base_attribute_;
};  // class Base

//=========================================

class Derived : public Base {
 public:
  // constructor
  Derived(int value, int base_value)
      : Base(base_value), 
      derived_attribute_{value} {
    /*empty body*/
  }

  virtual void greet() {
    std::cout << "Hello from Derived\n";
  }

 protected:
  int derived_attribute_;
};  // class Derived
