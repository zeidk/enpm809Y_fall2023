#include "static_attribute.h"
#include "static_method.h"


//-- static attribute
int DemoStaticAttribute::count = 0;  // initialization of class attribute

int main() {
  DemoStaticAttribute c1;
  std::cout << "Initial count: " << c1.get_count() << '\n';  // 1

  DemoStaticAttribute c2, c3;
  std::cout << "After creating three objects: " << c2.get_count() << '\n';  // 3
  std::cout << "After creating three objects: " << c3.get_count() << '\n';  // 3
}

//-- static method
// int DemoStaticMethod::count = 0;  // initialize class attribute

// int main() {
//   std::cout << "Initial count: " << DemoStaticMethod::get_count() << '\n';

//   DemoStaticMethod d1, d2, d3;
//   std::cout << "After creating 3 objects: " << DemoStaticMethod::get_count()
//             << '\n';
// }