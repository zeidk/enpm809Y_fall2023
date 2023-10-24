#pragma once
#include <iostream>

class Base {
 public:
  int base_public_{10};

 protected:
  int base_protected_{20};

 private:
  int base_private_{30};
};  // class Base
//---------------------------
class DerivedPublic : public Base {
 public:
  void print_members() {
    std::cout << base_public_ << '\n';
    std::cout << base_protected_ << '\n';
    // std::cout << base_private_ << '\n';
  }

 private:
  int x_;
};  // class DerivedPublic
//---------------------------
class DerivedProtected : protected Base {
 public:
  void print_members() {
    std::cout << base_public_ << '\n';
    std::cout << base_protected_ << '\n';
    // std::cout << base_private_ << '\n';
  }

 private:
  int y_;
};  // class DerivedProtected
//---------------------------
class DerivedPrivate : private Base {
 public:
  void print_members() {
    std::cout << base_public_ << '\n';
    std::cout << base_protected_ << '\n';
    // std::cout << base_private_ << '\n';
  }

 private:
  int z_;
};  // class DerivedPrivate