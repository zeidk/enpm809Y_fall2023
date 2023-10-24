#pragma once
#include <iostream>

class Base {
 public:
  virtual void method1() {
    std::cout << "Base::method1() called\n";
  }
  virtual void method2() {
    std::cout << "Base::method2() called\n";
  }
};  // class Base

//=========================================

class Derived : public Base {
 public:
  void method1() {
    std::cout << "Derived::method1() called\n";
  }
};  // class Derived
