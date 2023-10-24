#include <iostream>

class Base {
 public:
  Base(int base_value = 50) : 
    base_member_{base_value} { 
        /*empty body*/
  }

 protected:
  int base_member_;
};  // class Base

class Derived : public Base {
 public:
  Derived(double derived_value)
      : derived_member_{derived_value}  {
    /*empty body*/
  }

 private:
  double derived_member_;
};  // class Derived

// class A {
//  public:
//   A(int a_value) : a_member_{a_value} {
//     /*empty body*/
//   }

//  protected:
//   int a_member_;
// };  // class A

// class B {
//  public:
//   B(double b_value, int a_value) : b_member_{b_value}, a_(a_value){
//     /*empty body*/
//   }

//  private:
//   double b_member_;
//   A a_;
// };  // class B
