#include <iostream>

class Base {
 public:
  int base_public_member;
  Base()
      : base_public_member{0},
        base_protected_member{0},
        base_private_member{0} {}

 protected:
  int base_protected_member;

 private:
  int base_private_member;
};

class A : public Base {
 public:
  void print_members() {
    std::cout << base_public_member << '\n';
    std::cout << base_protected_member << '\n';
    // std::cout << private_member << '\n';
  }
  private:
    int a_private_member;
};

class B : protected Base {
 public:
  void print_members() {
    std::cout << base_public_member << '\n';
    std::cout << base_protected_member << '\n';
    // std::cout << base_private_member << '\n';
  }

 private:
  int b_private_member;
};

class C : private Base {
 public:
  void print_members() {
    std::cout << base_public_member << '\n';
    std::cout << base_protected_member << '\n';
    // std::cout << base_private_member << '\n';
  }

 private:
  int c_private_member;
};
