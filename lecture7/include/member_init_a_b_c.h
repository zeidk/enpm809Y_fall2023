#pragma once
#include <iostream>

/**
 * @brief Class A
 * 
 */
class A {
 public:
  A() { std::cout << "default ctor A\n"; }
  A(int x) : v_{x} { std::cout << "param ctor A\n"; }

 private:
  int v_;
};  // class A

//==============================================================================
/**
 * @brief Class B
 *
 */
class B {
 public:
  B() {
    std::cout << "default ctor B\n";
    a_ = A(2);  // calls param ctor for A
  }

 private:
  A a_;  // calls default ctor for A
};       // class B

//==============================================================================
/**
 * @brief Class C
 *
 */
// class C {
//  public:
//   C(int v) {
//     v_ = v;
//     std::cout << "v_: " << v_ << '\n';
//   }

//  private:
//   const int v_;
// };  // class C