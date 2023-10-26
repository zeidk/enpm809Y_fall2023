#include <iostream>

class Base {
 public:
  int base_public_member;
  Base()
      : base_public_member{10},
        base_protected_member{20},
        base_private_member{30} {}

 protected:
  int base_protected_member;

 private:
  int base_private_member;
};

class DerivedPublic : public Base {
 public:
  void print_members() {
    std::cout << base_public_member << '\n';
    std::cout << base_protected_member << '\n';
    // std::cout << private_member << '\n';
  }
  private:
    int x_;
};

class DerivedProtected : protected Base {
 public:
  void print_members() {
    std::cout << base_public_member << '\n';
    std::cout << base_protected_member << '\n';
    // std::cout << base_private_member << '\n';
  }

 private:
  int y_;
};

class DerivedPrivate : private Base {
 public:
  void print_members() {
    std::cout << base_public_member << '\n';
    std::cout << base_protected_member << '\n';
    // std::cout << base_private_member << '\n';
  }

 private:
  int z_;
};
