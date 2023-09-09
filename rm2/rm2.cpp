#include <iostream>

int main() {
  //--------------------------------
  //-- SLIDE 10
  //--------------------------------
  //   std::cout << "Enter your age: ";
  //   unsigned short age{};
  //   std::cin >> age;

  //   if (age >= 18)
  //     std::cout << "You can vote!\n";

  //--------------------------------
  //-- SLIDE 12
  //--------------------------------

  // --1
  //   int a{2};
  //   if (a > 0)
  //     std::cout << "a is positive\n";
  //   a = -a;  // this is always executed

  // --2
  //   int a{2};
  //   if (a < 0) {
  //     std::cout << "a is positive\n";
  //   }
  //   a = -a;  // this is always executed

  // --3
  //   int a{2};
  //   if (a < 0) {
  //     std::cout << "a is positive\n";
  //     a = -a;  // executed only if a is negative
  //   }

  //--------------------------------
  //-- SLIDE 13
  //--------------------------------
  //   int a{1};

  //   if (a >= 0)
  //     std::cout << "a is positive\n";  // executed only if a>=0 is true
  //   else
  //     std::cout << "a is negative\n";  // executed only if a<0 is true

  //--------------------------------
  //-- SLIDE 16
  //--------------------------------

  //--1
  //   int x{1};

  //   if (x % 2)
  //     std::cout << x << " is even\n";
  //   else
  //     std::cout << x << " is odd\n";

  //--2
  //   int x{1};
  //   std::cout << ((x % 2) ? "x is even\n" : "x is odd\n");

  //--------------------------------
  //-- SLIDE 17
  //--------------------------------
  //   constexpr int x{3};
  //   constexpr int y{2};

  //   constexpr int larger_value{x > y ? x : y};  // initialize larger_value
  //   std::cout << "The larger value is: " << larger_value << '\n';  // 3

  //--------------------------------
  //-- SLIDE 18
  //--------------------------------
  //   constexpr int x{3};
  //   constexpr int y{2};

  //   if (x > y)
  //     constexpr int larger_value{x};
  //   else
  //     constexpr int larger_value{y};

  //   std::cout << "The larger value is: " << larger_value << '\n';

  //--------------------------------
  //-- SLIDE 19
  //--------------------------------
  //   int a{1};

  //   if (a > 0)
  //     std::cout << "Value is positive\n";  // if a > 0 is true
  //   else if (a < 0)
  //     std::cout << "Value is negative\n";  // if a < 0 is true
  //   else
  //     std::cout << "Value is zero\n";  // if a > 0 AND a < 0 are false

  //--------------------------------
  //-- SLIDE 21
  //--------------------------------
  //   if (2)    // converted to true
  //     std::cout << "Condition is true\n"; // executed
  //   if (0.01) // converted to true
  //     std::cout << "Condition is true\n"; // executed
  //   if (0)    // converted to false
  //     std::cout << "Condition is true\n"; // not executed
  //   if (0.0)  // converted to false
  //     std::cout << "Condition is true\n"; // not executed

  //--------------------------------
  //-- SLIDE 22
  //--------------------------------

  //   int x{5};
  //   int y{10};

  //   if (x > 0)
  //     if (y > 0)
  //       std::cout << "x and y are positive\n";
  //   else
  //     std::cout << "x is non-positive\n";
}