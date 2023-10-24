#pragma once

class Base {
 public:
  Base(int base_value = 50)
      : base_member_{base_value} {
    /*empty body*/
  }

 protected:
  int base_member_;
};  // class Base

//------------------------------------
class Derived : public Base {
 public:
  Derived(double derived_value)
      : derived_member_{derived_value} {
    /*empty body*/
  }

 private:
  double derived_member_;
};  // class Derived