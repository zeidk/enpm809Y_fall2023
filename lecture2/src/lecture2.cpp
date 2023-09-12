#include <iomanip>
#include <iostream>
#include <typeinfo>

#define PI 3.14159  // symbolic constant

int global_var{1};

void my_function() {
  global_var++;
}

// namespace MyNamespace
// namespace MyNamespace {
// int x{3};
// int y{4};
// }  // end namespace MyNamespace

namespace MyNamespace
{
  int cout{1};
} // end namespace MyNamespace
using namespace MyNamespace;
using namespace std;

int main() {
  // int hex = 0x2A;
  // int oct = 052;
  // std::cout << hex << '\n';
  // std::cout << oct << '\n';
  //----------------------------
  //-- SLIDE 11
  //----------------------------
  // int break1;   // OK
  // int break_1;  // OK
  // int Break1;   // OK
  // int BREAK;    // OK
  // int _break1;  // OK
  // int 1Break;   // error

  //----------------------------
  //-- SLIDE 13
  //----------------------------
  // int number;
  // int number = 20;
  // int number2 = 20;
  // // std::cout << &number << '\n';
  // std::cout << &number << '\n';
  // std::cout << &number2 << '\n';

  //----------------------------
  //-- SLIDE 18
  //----------------------------
  // int number;                   // declaration
  // number = 1;                   // assignment
  // std::cout << number << '\n';  // 1
  // number = 2;                   // assignment
  // std::cout << number << '\n';  // 2

  //----------------------------
  //-- SLIDE 21
  //----------------------------
  // int a{};                 // zero-initialized to 0
  // std::cout << a << '\n';  // 0
  // double b{};              // zero-initialized to 0.0
  // std::cout << b << '\n';  // 0
  // std::cout << std::fixed << std::setprecision(2) << b << std::endl;

  //----------------------------
  //-- SLIDE 22
  //----------------------------
  // int number{};                   // uninitialized
  // std::cout << &number << '\n';
  // std::cout << number << '\n';  // garbage data

  //----------------------------
  //-- SLIDE 24
  //----------------------------
  // int x{1 + 2};
  // std::cout << x << '\n';
  // x++;
  // std::cout << x << '\n';
  // x--;
  // std::cout << x << '\n';
  // x += 2;
  // std::cout << x << '\n';
  // x -= 3;
  // std::cout << x << '\n';
  // x *= 2;
  // std::cout << x << '\n';
  // x /= 4;
  // std::cout << x << '\n';  // 1

  // int y{1};
  // std::cout << y << '\n';
  // y += 2;  // y = y + 2;
  // std::cout << y << '\n';
  // y =+ 2;
  // std::cout << y << '\n';

  // int x{5}; // x = 5
  // // int y = x--; //x = x -1
  // // x = x - 1;
  // // int y = x;
  // int y{--x};  // x = x -1
  // std::cout << x << '\n';
  // std::cout << y << '\n';
  // int x{5};
  // int y{};
  // { y = x--; }
  // int y{--x};
  // // int y and y = --x;
  // std::cout << x << '\n';
  // std::cout << y << '\n';

  // {
  //   int x{5};
  //   // int y{--x};
  //   std::cout << x << '\n';
  //   std::cout << y << '\n';
  // }
  //----------------------------
  //-- SLIDE 27
  //----------------------------
  // double num1 = 1.5;
  // int num2 = num1; // 1.5 converted to 1
  // std::cout << "Value of num1 : " << num1 << '\n';  // 1.5
  // std::cout << "Type of num1 : " << typeid(num1).name() << '\n';  // double
  // std::cout << "Value of num2 : " << num2 << '\n';                // 1

  //----------------------------
  //-- SLIDE 31
  //----------------------------



  // short s{1};
  // int num1 = s;                    // short promoted to int
  // int num2 = 'a';                  // char promoted to int
  // int num3 = false;
  // bool b = 0;                     // bool promoted to int
  // // std::cout << num1 << '\n';       // 1
  // // std::cout << num2 << '\n';       // 97
  // // std::cout << num3 << '\n';       // 1
  // std::cout << std::boolalpha << b << '\n';       // 1
  // std::cout << sizeof(s) << '\n';  // 2

  //----------------------------
  //-- SLIDE 33
  //----------------------------
  // int a;
  // int b = 3.2;
  // int c(1.3);
  // int d{3.5};
  // std::cout << a << '\n';
  // std::cout << b << '\n';
  // std::cout << c << '\n';
  // std::cout << d << '\n';

  //----------------------------
  //-- SLIDE 38
  //----------------------------
  // int and long double are on the priority list
  // rule1: int converted to long double
  // int a{4};
  // long double b{3.323223};
  // std::cout << typeid(a + b).name() << ' ' << a + b
  //           << '\n';  // long double 7.32322

  // // double is on the priority list
  // // short is not on the priority list
  // // rule1: short is converted to double
  // double c{1.5};
  // short d{1};
  // std::cout << typeid(c + d).name() << ' ' << c + d << '\n';  // double 2.5

  // // short is not on the priority list
  // // rule2: short is promoted to int
  // short e{1};
  // short f{1};
  // std::cout << typeid(e + f).name() << ' ' << e + f << '\n';  // int 2

  //----------------------------
  //-- SLIDE 39
  //----------------------------
  // std::cout << 3 / 2.0 << '\n';

  //----------------------------
  //-- SLIDE 41
  //----------------------------
  // int x{1};
  // std::cout << x << '\n';
  // std::cout << "hello, " << "world\n";
  // std::cout << x << " hello, "<< "world\n";

  //----------------------------
  //-- SLIDE 42
  //----------------------------
  // std::cout << "Enter your age: ";  // ask user for their age
  // unsigned short age{};             // init variable to hold user input
  // std::cin >> age;                  // store input in variable age
  // std::cout << "Your age is " << age << '\n';

  // std::cout << "Enter two integers separated by a space: ";
  // int a{};             // init variable to hold the first number
  // int b{};             // init variable to hold the second number
  // std::cin >> a >> b;  // store inputs in variables a and b
  // std::cout << "a: " << a << ", b: " << b << '\n';

  //----------------------------
  //-- SLIDE 43
  //----------------------------
  // std::cout << "Enter two integers separated by a space: ";
  // double a{};             // init variable to hold the first number
  // int b{};          // init variable to hold the second number
  // int c{};
  // std::cin >> a >> b >> c;  
  // std::cout << "a: " << a << ", b: " << b << ", c: " << c << '\n';

  //----------------------------
  //-- SLIDE 47
  //----------------------------
  // const double pi;
  // const double pi{3.141598};
  // pi = 3.14;  // error

  //----------------------------
  //-- SLIDE 48
  //----------------------------
  // std::cout << "pi: " << PI << '\n';

  //----------------------------
  //-- SLIDE 51
  //----------------------------
  // std::cout << "Enter an integer: ";
  // int input{};
  // std::cin >> input;
  // const int a{1};              // a is a compile-time const
  // const int b{input};          // b is a run-time const
  // std::cout << a + b << '\n';  // a + b is a run-time expression

  // {
  //   {
  //     {
  //       int x{1};
  //       std::cout << x << '\n';
  //     }
  //   }
  // }

  // std::cout << x << '\n';

  //----------------------------
  //-- SLIDE 52
  //----------------------------
  // constexpr int a{1};  // OK: a is a compile-time const
  // constexpr int b{2};  // OK: b is a compile-time const
  // std::cout << "Enter an integer: ";
  // int input{};
  // std::cin >> input;
  // constexpr int c{input};

  //----------------------------
  //-- SLIDE 53
  //----------------------------
  // auto num = 1234567890123456789;
  // std::cout << "Type of num : " << typeid(num).name() << '\n';

  //----------------------------
  //-- SLIDE 57
  //----------------------------
  // int a{1};
  // {
  //   int b{2};
  //   std::cout << a << '\n';  // 1
  //   std::cout << b << '\n';  // 2
  // }                          // b goes out of scope here.
  // std::cout << b << '\n';    // error: b is out of scope
  // int c{3};

  //----------------------------
  //-- SLIDE 59
  //----------------------------
  // std::cout << global_var << '\n';  // 1
  // global_var++;                     // 2
  // my_function();                    // 3
  // std::cout << global_var << '\n';  // 3

  //----------------------------
  //-- SLIDE 65--67
  //----------------------------
  // std::cout << MyNamespace::x << '\n';  // 3
  // std::cout << MyNamespace::y << '\n';  // 4

  //----------------------------
  //-- SLIDE 68
  //----------------------------
  // cout << "Hello World!" << '\n';
}
