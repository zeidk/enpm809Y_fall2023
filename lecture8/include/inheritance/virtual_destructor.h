#pragma once
#include <iostream>
#include <memory>

class Base {
 public:
  Base() {
    std::cout << "Base ctor" << '\n';
  }
  ~Base() {
    std::cout << "Base dtor" << '\n';
  }
  virtual void test() {
  }
};

class Derived : public Base {
 public:
  Derived()
      : Base(), x_{std::make_unique<int>(0)} {
    std::cout << "Derived ctor" << '\n';
  }
  ~Derived() {
    std::cout << "Derived dtor" << '\n';
  }
  void test() {
  }
  private:
   std::unique_ptr<int> x_;
};