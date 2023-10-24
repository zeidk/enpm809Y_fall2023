#include "static_polymorphism/vtable.h"
#include <iostream>
#include <memory>

int main(){
  std::unique_ptr<Base> base_ptr = std::make_unique<Base>();
  base_ptr->method1();
  base_ptr->method2();
  std::cout << sizeof (*base_ptr) << '\n';
  std::unique_ptr<Derived> derived_ptr1 = std::make_unique<Derived>();
  derived_ptr1->method1();
  derived_ptr1->method2();
  std::unique_ptr<Base> derived_ptr2 = std::make_unique<Derived>();
  derived_ptr2->method1();
  derived_ptr2->method2();

}