#include <iostream>
#include <typeinfo>

int main()
{
  //------------------//
  // SLIDE 16
  //------------------//
  // int x{10};
  // int *p_int{&x};
  // std::cout << &x << '\n';
  // std::cout << p_int << '\n';

  //------------------//
  // SLIDE 17
  //------------------//
  // int x{10};
  // std::cout << typeid(&x).name() << '\n';
  // int *p_int;
  // std::cout << typeid(p_int).name() << '\n';

  //------------------//
  // SLIDE 19
  //------------------//
  // int *a;    // a is a pointer to an int
  // std::cout << typeid(a).name() << '\n';
  // double *b; // b is a pointer to a double
  // std::cout << typeid(b).name() << '\n';
  // //bad practice
  // int *c, d; // c is a pointer to an int, d is a regular int
  // std::cout << typeid(c).name() << '\n';
  // std::cout << typeid(d).name() << '\n';

  //------------------//
  // SLIDE 22
  //------------------//
  // int x{3};
  // int *p1_int{&x};
  // int *p2_int{nullptr};
  // if (p1_int != p2_int)
  //   std::cout << "p1_int is not null" << '\n';
  // else
  //   std::cout << "p1_int is null" << '\n';

  //------------------//
  // SLIDE 23
  //------------------//
  // int x{10};
  // std::cout << &x << '\n';    // 0x7fffffffdb3c
  // std::cout << *(&x) << '\n'; // Which value is stored at 0x7fffffffdb3c?

  // int *p_int{&x};
  // std::cout << p_int << '\n';  // 0x7fffffffdb3c
  // std::cout << *p_int << '\n'; // Which value is stored at 0x7fffffffdb3c?

  //------------------//
  // SLIDE 24
  //------------------//
  // int x{10};
  // int *p_int{&x};

  // // Modify the value of x through p_int
  // *p_int = 20;

  // std::cout << x << '\n';      // 20
  // std::cout << *p_int << '\n'; // 20

  //------------------//
  // SLIDE 25
  //------------------//

  //----1
  // int x{10};
  // int *p_int{&x};

  // *p_int *= 2;

  // std::cout << x << '\n';
  // std::cout << *p_int << '\n';

  //----2
  // int a{2};
  // int *p_int{&a};
  // int **q_int{&p_int};
  // int ***r_int{&q_int};

  // std::cout << *p_int << '\n';
  // std::cout << **q_int << '\n';
  // std::cout << ***r_int << '\n';

  //------------------//
  // SLIDE 26
  //------------------//
  // int i{10};
  // double d{10.0};
  // float f{10.0f};
  // bool b{true};
  // char c{'a'};
  // std::string s{"Hello World!"};

  // int* p_int{&i};
  // double* p_double{&d};
  // float* p_float{&f};
  // bool* p_bool{&b};
  // char* p_char{&c};
  // std::string* p_string{&s};

  // std::cout << sizeof(p_int) << std::endl;
  // std::cout << sizeof(p_double) << std::endl;
  // std::cout << sizeof(p_float) << std::endl;
  // std::cout << sizeof(p_bool) << std::endl;
  // std::cout << sizeof(p_char) << std::endl;
  // std::cout << sizeof(p_string) << std::endl;

  //------------------//
  // SLIDE 27
  //------------------//
  // int x{5};
  // double y{2.5};
  // int *ptr_int{nullptr}; // OK
  // ptr_int = &x;          // OK
  // ptr_int = &y;          // error

  //------------------//
  // SLIDE 29
  //------------------//
  // int x{5};
  // int *p_int{&x};
  // std::cout << p_int << '\n'; // 0x7ffeeb2a5f80
  // p_int++;                    // 0x7ffeeb2a5f80 + 1 * sizeof(int) = 0x7ffeeb2a5f80 + 4
  // std::cout << p_int << '\n'; // 0x7ffeeb2a5f84

  //------------------//
  // SLIDE 30
  //------------------//
  // int x{5};
  // int *p_int{&x};
  // std::cout << p_int << '\n'; // 0x7ffcb5318adc
  // p_int += 2;                 // 0x7ffcb5318adc + 2 * sizeof(int) = 0x7ffcb5318adc + 8
  // std::cout << p_int << '\n'; // 0x7ffcb5318ae4

  //------------------//
  // SLIDE 31
  //------------------//
  // int x{5};
  // int y{5};

  // int* p1_int{&x};  // p1 points to x
  // int* p2_int{&y};  // p2 points to y
  // int* p3_int{&x};  // p3 points to x

  // std::cout << std::boolalpha;              // print bools as true/false
  // std::cout << (p1_int == p2_int) << '\n';  // false (different addresses)
  // std::cout << (p1_int == p3_int) << '\n';  // true  (same address)

  //------------------//
  // SLIDE 32
  //------------------//
  // int x{10};
  // int y{20};

  // int* p1_int{&x};  // p1_int points to x
  // int* p2_int{&y};  // p2_int points to y
  // int* p3_int{&x};  // p3_int points to x

  // std::cout << std::boolalpha;  // print bools as true/false
  // std::cout << (*p1_int == *p2_int) << '\n';  // false
  // std::cout << (*p1_int == *p3_int) << '\n';  // true
  // std::cout << (*p1_int > *p2_int) << '\n';   // false
  // std::cout << (*p1_int >= *p2_int) << '\n';  // false
  // std::cout << (*p1_int < *p2_int) << '\n';   // true
  // std::cout << (*p1_int <= *p2_int) << '\n';  // true
  // std::cout << (*p1_int != *p2_int) << '\n';  // true

  //------------------//
  // SLIDE 34
  //------------------//
  // int x{2};
  // int y{3};

  // /* pointer to const */
  // const int *p1_int;
  // p1_int = &x; // OK
  // p1_int = &y; // OK
  // *p1_int = 3; // error

  // /* const pointer */
  // int *const p2_int{&x};
  // *p2_int = 3; // OK
  // int y{3};
  // p2_int = &y; // error

  // /* const pointer to const */
  // const int *const p3_int{&x};
  // *p3_int = 3; // error
  // p3_int = &y; // error

  //------------------//
  // SLIDE 38
  //------------------//
  // int *p_int{new int{15}};
  // std::cout << p_int << '\n'; // 0x55555556b2b0
  // delete p_int;
  // std::cout << p_int << '\n';  // 0x55555556b2b0
  // std::cout << *p_int << '\n'; // Garbage (UB)

  //------------------//
  // SLIDE 39
  //------------------//
  // int *p_int{new int{5}}; // allocate and point to data on the heap
  // delete p_int;           // free the heap memory
  // int x{2};               // create x is on the stack
  // p_int = &x;             // point to data on the stack
  // p_int = new int{3};     // allocate and point to data on the heap
  // delete p_int;           // free the heap memory
  // p_int = nullptr;        // null pointer

  //------------------//
  // SLIDE 40
  //------------------//
  // int x{3};
  // int *p_int{&x};
  // delete p_int; // UB

  //------------------//
  // SLIDE 41
  //------------------//
  // int *p_int{nullptr};
  // delete p_int; // safe to delete a null pointer

  //------------------//
  // SLIDE 44
  //------------------//
  // int *p_int{new int{2}};
  // delete p_int;                // p_int is dangling
  // *p_int = 5;                  // UB
  // std::cout << *p_int << '\n'; // UB

  //------------------//
  // SLIDE 45
  //------------------//
  // {
  //   int *p_int{new int{5}};
  //   int x{10};
  //   p_int = &x; // we just lost our only way of accessing the heap memory location
  // }             // p_int is destroyed here, but the memory it points to is not freed (memory leak)

  //------------------//
  // SLIDE 46
  //------------------//
  // int *p1_int{new int{2}};
  // int *p2_int{p1_int};

  // delete p1_int;
  // p1_int = nullptr;

  // delete p2_int; // UB

  //------------------//
  // SLIDE 47
  //------------------//
  // {
  //   int *p_int{nullptr};
  //   std::cout << *p_int << '\n'; // dereferencing a null pointer: UB
  // }

  // {
  //   int *p_int{nullptr};
  //   if (p_int)
  //   {                              // if p is not null
  //     std::cout << *p_int << '\n'; // it's ok to derefence it
  //   }
  //   else
  //   { // if p is null
  //     // print error, assign pointer, do nothing at all, etc
  //     // but do not derefence it
  //     std::cout << "pointer is null\n";
  //   }
  // }

  //------------------//
  // SLIDE 50
  //------------------//
  // int x{10};
  // int& ref{x};  // ref is a reference to x
  // ref = 20;     // x is now 20
  // std::cout << x << '\n';
  // x = 30;  // ref is now 30
  // std::cout << ref << '\n';

  //------------------//
  // int& ref;  // error: a reference must be initialized

  //------------------//
  // int x{10};
  // int y{20};
  // int& ref{x};                // ref is a reference to x
  // ref = y;
  // std::cout << &x << '\n';    // 0x7fffffffdadc
  // std::cout << &y << '\n';    // 0x7fffffffdadc
  // std::cout << &ref << '\n';  // 0x7fffffffdadc
  //------------------//
  // int x{10};
  // int& ref{x};                // ref is a reference to x
  // std::cout << &x << '\n';    // 0x7fffffffdadc
  // std::cout << &ref << '\n';  // 0x7fffffffdadc

  //------------------//
  // SLIDE 52
  //------------------//
  // Allocate memory for two integers
  // int *p1_int{new int{40}};
  // int *p2_int{new int{50}};

  // p1_int = new int{100};
  // delete p2_int;
  // *p2_int = 5;
  // p1_int = p2_int;
  // *p1_int = 500;
  // delete p1_int;
}