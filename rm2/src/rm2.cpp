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

  //--------------------------------
  //-- SLIDE 30
  //--------------------------------
  //   int a{3};

  //   switch (a) {
  //     case 1:  // no match
  //       std::cout << "one\n";
  //       break;
  //     case 2:  // no match
  //       std::cout << "two\n";
  //       break;
  //     default:  // executed since no cases matched
  //       std::cout << "unknown\n";
  //       break;
  //   }

  //--------------------------------
  //-- SLIDE 31
  //--------------------------------

  //   int a{3};

  //   switch (a) {
  //     case 1:
  //       std::cout << "one\n";
  //       break;
  //     case 2:
  //       std::cout << "two\n";
  //       break;
  //     default:
  //       std::cout << "unknown\n";
  //       break;
  //   }

  //   std::cout << "switch has terminated\n";

  //--------------------------------
  //-- SLIDE 33-34
  //--------------------------------
  //   int choice{1};

  //   switch (choice) {
  //     case 1:                          // we have a match here
  //       std::cout << "Choice is 1\n";  // this is executed
  //       //[[fallthrough]];               // compiler will not raise a warning
  //     case 2:
  //       std::cout << "Choice is 2\n";  // I want to execute this as well
  //       break;
  //     default:
  //       std::cout << "Unknown choice\n";
  //   }

  //--------------------------------
  //-- SLIDE 35
  //--------------------------------
  //   int a{2};
  //   std::cout << "Do you want to double the value of variable a? (y/n) ";
  //   char input{};
  //   std::cin >> input;

  //   switch (input) {
  //     case 'y':
  //     case 'Y':
  //       a *= 2;  // double the number
  //       break;
  //     case 'n':
  //     case 'N':
  //       break;  // not doing anything
  //     default:
  //       std::cout << "unknown input\n";
  //       break;
  //   }
  //   std::cout << "Value of a: " << a << '\n';

  //--------------------------------
  //-- SLIDE 35
  //--------------------------------
  //   int x{1};

  //   switch (x) {
  //     case 1:
  //       int i{10};
  //       std::cout << i << '\n';
  //       break;
  //     case 2:  // |\codeerrorII{error}|: jump to case label
  //       int j{20};
  //       std::cout << j << '\n';
  //       break;
  //   }

  //--------------------------------
  //-- SLIDE 40
  //--------------------------------
  //   int counter{1};

  //   while (counter <= 10) {
  //     std::cout << counter << ' ';
  //     ++counter;
  //   }
  //   std::cout << '\n';

  //--------------------------------
  //-- SLIDE 41
  //--------------------------------
  //   while (true) {  // infinite loop
  //     std::cout << "Loop again (y/n)? ";
  //     char input{};
  //     std::cin >> input;

  //     if (input == 'n'){
  //       std::cout << "Stopping the loop\n";
  //       return 0;
  //     }

  //   }

  //--------------------------------
  //-- SLIDE 43
  //--------------------------------
  // outer loop loops 5 times
  //   int outer{1};
  //   while (outer <= 5) {
  //     int inner{1};
  //     // inner loop loops 10 times
  //     while (inner <= 10) {
  //       std::cout << outer * inner << ' ';
  //       ++inner;
  //     }
  //     // print a newline at the end of each row
  //     std::cout << '\n';
  //     ++outer;
  //   }

  //--------------------------------
  //-- SLIDE 46
  //--------------------------------
  // selection must be declared outside of the do/while so we can use it later
  //   int selection{};

  //   do {
  //     std::cout << "Which approach do you want to use (1 or 2)?:\n";
  //     std::cout << "1) Breadth-first search\n";
  //     std::cout << "2) Depth-first search\n";
  //     std::cout << "Please select an approach: ";
  //     std::cin >> selection;
  //   } while (selection != 1 && selection != 2);

  //   switch (selection) {
  //     case 1:
  //       std::cout << "You selected: Breadth-first\n";
  //       break;
  //     case 2:
  //       std::cout << "You selected: Depth-first search\n";
  //       break;
  //   }

  //--------------------------------
  //-- SLIDE 51
  //--------------------------------

  //   int count{0};
  //   for (; count < 10;) {  // no init_statement or end_expression
  //     std::cout << count << ' ';
  //     ++count;
  //   }
  //   std::cout << '\n';
  //   std::cout << "The final value of count is: " << count << '\n';

  //--------------------------------
  //-- SLIDE 52
  //--------------------------------
  //   //decrement is also possible. Also note the use of auto keyword.
  //   for (auto i{9}; i >= 0; --i)
  //     std::cout << i << " ";

  //   std::cout << "\n---------\n";

  //   // although not often used, multiple counters are also possible
  //   for (auto i{0}, j{0}; i < 3; ++i, --j)
  //     std::cout << i << ' ' << j << '\n';

  //   std::cout << "---------\n";

  //   // nested loops
  //   for (auto i{1}; i < 6; ++i) {
  //     for (auto j{1}; j < 11; ++j) {
  //       std::cout << i * j << ' ';
  //     }
  //     std::cout << '\n';
  //   }

  //--------------------------------
  //-- SLIDE 55
  //--------------------------------
  //   // iterate 10 times
  //   for (auto i{0}; i < 10; ++i) {
  //     // exit loop if i is 3
  //     if (i == 3)
  //       break;  // exit the loop now

  //     // otherwise print i
  //     std::cout << i << ' ';
  //   }

  //   // execution will continue here after the break
  //   std::cout << "\nResuming program execution\n";

  //--------------------------------
  //-- SLIDE 56
  //--------------------------------
  //   while (true) {  // infinite loop
  //     std::cout << "Loop again (y/n)? ";
  //     char input{};
  //     std::cin >> input;

  //     if (input == 'n')
  //       break;
  //   }

  //   // execution will continue here after the break
  //   std::cout << "Resuming program execution\n";

  //--------------------------------
  //-- SLIDE 57
  //--------------------------------
  //   int num{};

  //   do {
  //     std::cout << "Enter a number (-1 to exit): ";
  //     std::cin >> num;

  //     if (num == -1) {
  //       break;  // Exit the loop when -1 is entered
  //     }
  //     std::cout << "You entered: " << num << '\n';
  //   } while (true);  // Infinite loop, but we have a break condition inside

  //   std::cout << "You chose to exit.\n";

  //--------------------------------
  //-- SLIDE 59
  //--------------------------------
  //   int a{0};
  //   do {
  //     if (a == 2) {
  //       a++;       // increment a
  //       continue;  // skip everything else in the body of the do statement
  //     }
  //     std::cout << "Value of a: " << a << '\n';
  //     a++;
  //   } while (a < 5);

  //--------------------------------
  //-- SLIDE 60
  //--------------------------------
  //   for (auto i{0}; i < 10; ++i) {
  //     // if the number is divisible by 3, skip this iteration
  //     if ((i % 3) == 0)
  //       continue;  // go to next iteration

  //     // If the number is not divisible by 3, print it
  //     std::cout << i << ' ';
  //   }
  //   std::cout << '\n';

  //--------------------------------
  //-- SLIDE 61
  //--------------------------------
  //   auto count{1};
  //   while (count < 11) {
  //     if ((count % 3) == 0) {
  //       ++count;   // infinite loop if we omit this line
  //       continue;  // go to next iteration
  //     }

  //     // If the number is not divisible by 3, keep going
  //     std::cout << count << ' ';
  //     ++count;
  //   }

  //--------------------------------
  //-- SLIDE 67
  //--------------------------------
  //   int x{5};
  //   int y{-3};
  //   std::cout << +x << '\n';  // 5
  //   std::cout << -x << '\n';  // -5
  //   std::cout << +y << '\n';  // -3
  //   std::cout << -y << '\n';  // 3

  //--------------------------------
  //-- SLIDE 69
  //--------------------------------
  //   std::cout << 4 / 3 << '\n';                       // 1
  //   std::cout << 4.0 / 3 << '\n';                     // 1.33333
  //   std::cout << 4 / 3.0 << '\n';                     // 1.33333
  //   std::cout << 4.0 / 3.0 << '\n';                   // 1.33333

  //   int x{3};
  //   int y{2};
  //   std::cout << x / y << '\n';                       // 1
  //   std::cout << static_cast<double>(x) / y << '\n';  // 1.5

  //--------------------------------
  //-- SLIDE 74-1
  //--------------------------------
  //   int a{2};
  //   int b{++a};  // increment a first then initialize b
  //   int c{--a};  // decrement a first then initialize c

  //   std::cout << a << ' ' << b << ' ' << c << '\n';  // 2 3 2

  //--------------------------------
  //-- SLIDE 74-2
  //--------------------------------
  //   int a{2};
  //   int b{a++};  // initialize b and then increment a
  //   int c{a--};  // initialize c and then decrement a

  //   std::cout << a << ' ' << b << ' ' << c << '\n';  // 2 2 3

  //--------------------------------
  //-- SLIDE 79
  //--------------------------------
  //   std::cout << "Enter two integers: ";
  //   int x{};
  //   int y{};
  //   std::cin >> x >> y;

  //   if (x == y)
  //     std::cout << x << " equals " << y << '\n';
  //   if (x != y)
  //     std::cout << x << " does not equal " << y << '\n';
  //   if (x > y)
  //     std::cout << x << " is greater than " << y << '\n';
  //   if (x < y)
  //     std::cout << x << " is less than " << y << '\n';
  //   if (x >= y)
  //     std::cout << x << " is greater than or equal to " << y << '\n';
  //   if (x <= y)
  //     std::cout << x << " is less than or equal to " << y << '\n';

  //--------------------------------
  //-- SLIDE 82
  //--------------------------------
  //   int a{2};
  //   int b{4};
  //   if (!(a > b)) {
  //     std::cout << b << " is greater than " << a << '\n';
  //   }

  //--------------------------------
  //-- SLIDE 83
  //--------------------------------
  //   int a{2};
  //   int b{4};
  //   if (!a > b) {  // we removed the parentheses
  //     std::cout << b << " is greater than " << a << '\n';
  //   }

  //--------------------------------
  //-- SLIDE 84
  //--------------------------------
//   int a{2};
//   if (a == 1 || a == 2 || a == 4) {
//     std::cout << "a is 1, 2, or 4\n";
//   }

  //--------------------------------
  //-- SLIDE 85
  //--------------------------------
//   int a{2};
//   if (a > 0 && a < 6 && a != 3) {
//     std::cout << "a is between 1 and 5 and is not 3\n";
//   }

}  // end of main