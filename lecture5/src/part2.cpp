#include <functional>
#include <iostream>
#include <unordered_map>

//--------------------------------
// SLIDE 54
//--------------------------------

// int add(int a, int b) { return a + b; }
// double multiply(double a, double b) { return a * b; }

// void say_hello() { std::cout << "hello\n"; }
// void greet(const std::string& name) { std::cout << name << "\n"; }

// int main()
// {
//   // declare std::function<int(int, int)>
//   std::function<int(int, int)> math;
//   // OK, int add(int, int) matches <int(int, int)>
//   math = add;
//   std::cout << math(1, 2) << '\n';  // 3
//   // @\codeerror@, double multiply(double, double) does not match <int(int,
//   // int)>
//   math = multiply;  // @\codeerror@
//   std::cout << math(2, 3) << '\n';

//   // declare std::function<void()>
//   std::function<void()> print;
//   // OK, void say_hello() matches <void()>
//   print = say_hello;
//   print();  // hello
//   // error, void greet(std::string) does not match <void()>
// //   print = greet;  // error
// //   print();
// }

//--------------------------------
// SLIDE 57
//--------------------------------

// int add(int a, int b) { return a + b; }
// int multiply(int a, int b) { return a * b; }
// double divide(double a, double b) { return a / b; }

// int main()
// {
//   // declare a pointer which can reference any function with int(int, int)
//   int (*my_ptr)(int, int){nullptr};

//   // OK, int add(int, int) matches int(int, int)
//   my_ptr = add;
//   std::cout << my_ptr(1, 2) << '\n';  // call add(1, 2) through my_ptr

//   // OK, int multiply(int, int) matches int(int, int)
//   my_ptr = multiply;
//   std::cout << my_ptr(2, 3) << '\n';  // call multiply(2, 3) through my_ptr

//   // error double divide(double, double) does not match int(int, int)
//   //   my_ptr = divide;  // error
//   //   std::cout << my_ptr(5.3, 2.5) << '\n';
// }

//--------------------------------
// SLIDE 58
//--------------------------------
// int add(int a, int b) { return a + b; }

// // higher-order function
// int do_math(int a, int b, std::function<int(int, int)> custom_function)
// {
//   return custom_function(a, b);
// }

// int main()
// {
//   // function pointer to 'add'
//   int (*my_ptr)(int, int) = add;
//   // using std::function to wrap the function pointer
//   std::function<int(int, int)> wrapped_function = my_ptr;
//   // calling the wrapped function
//   auto result = do_math(1, 2, wrapped_function);
//   std::cout << result << '\n';
// }

//--------------------------------
// SLIDE 60
//--------------------------------
// double add(double a, double b) { return a + b; }
// double subtract(double a, double b) { return a - b; }

// int main()
// {
//   // Declare a function pointer for operations
//   double (*operation)(double, double) = nullptr;

//   std::cout << "Choose an operation: + or -: ";
//   char choice;
//   std::cin >> choice;

//   // Assign the function pointer based on user choice
//   switch (choice)
//   {
//     case '+':
//       operation = add;
//       break;
//     case '-':
//       operation = subtract;
//       break;
//     default:
//       std::cout << "Invalid operation!" << std::endl;
//       return 1;  // exit the main function
//   }

//   double num1{};
//   double num2{};
//   std::cout << "Enter two numbers: ";
//   std::cin >> num1 >> num2;

//   // Use the function pointer to perform the operation
//   double result = operation(num1, num2);
//   std::cout << "Result: " << result << std::endl;
// }

//--------------------------------
// SLIDE 61
//--------------------------------
// double add(double a, double b) { return a + b; }
// double subtract(double a, double b) { return a - b; }

// int main()
// {
//   // table mapping operation symbols to corresponding functions
//   std::unordered_map<char, double (*)(double, double)> operations = {
//       {'+', add}, {'-', subtract}};

//   char operation{};
//   double num1{};
//   double num2{};

//   std::cout << "Enter an expression (e.g., 1.5 + 7.6): ";
//   std::cin >> num1 >> operation >> num2;

//   // look up the operation in the table
//   auto it = operations.find(operation);
//   if (it != operations.end())
//     std::cout << "Result: " << it->second(num1, num2) << '\n';
//   else
//     std::cout << "Invalid operation!\n";
// }

//--------------------------------
// SLIDE 65
//--------------------------------

// int main()
// {
// //   // example 1
// //   []() -> void { std::cout << "hello, world\n"; }();
// //   auto print_hello_world = []() -> void { std::cout << "hello, world\n";
// };
// //   print_hello_world();

// //   // example 2
// //   std::cout << [](int a, int b) -> int { return a + b; }(1, 2) << '\n';
// //   auto sum = [](int a, int b) -> int { return a + b; };
// //   std::cout << sum(1, 2) << '\n';

// //   // example 3
// //   int x{10};
// //   int y{20};
// //   std::cout << [x, y]() { return x + y; }() << '\n';
// //   auto sum2 = [x, y]() { return x + y; };
// //   std::cout << sum2() << '\n';
// }

//--------------------------------
// SLIDE 66
//--------------------------------

// // higher-order function
// int do_math(int a, int b, const std::function<int(int, int)> custom_function)
// {
//   return custom_function(a, b);
// }

// int main()
// {
//   std::function<int(int, int)> add = [](int a, int b) { return a + b; };
//   std::cout << do_math(1, 2, add) << '\n';  // 3
// }

//--------------------------------
// SLIDE 68
//--------------------------------

// int main()
// {
//   std::vector<int> v1 = {1, 2, 3};
//   std::for_each(v1.begin(), v1.end(), [](int &n) { n *= 2; });
//   for (auto n : v1) std::cout << n << ' ';               // 2 4 6

//   std::vector<int> v_in = {1, 2, 3};
//   std::vector<int> v_out(v_in.size());
//   std::transform(v_in.begin(), v_in.end(), v_out.begin(), [](int n) { return n * n; });
//   for (auto n : v_out) std::cout << n << ' '; // 1 4 9

//   std::vector<int> v2 = {4, 4, 2, 3, 1};
//   auto evens = std::count_if(v2.begin(), v2.end(), [](int n) { return n % 2 == 0; });
//   std::cout << evens << '\n';  // 3
// }

//--------------------------------
// SLIDE 69
//--------------------------------
// int add(int a, int b) { return a + b; }

// // higher-order function
// int do_math(int a, int b, std::function<int(int, int)> custom_function)
// {
//   return custom_function(a, b);
// }

// int main()
// {
//   // wrapping a named (regular) function
//   std::function<int(int, int)> wrapped_function_simple = add;

//   // wrapping a function pointer
//   int (*ptr_add)(int, int) = add;
//   std::function<int(int, int)> wrapped_function_pointer = ptr_add;

//   // wrapping a lambda function
//   std::function<int(int, int)> wrapped_function_lambda = [](int a, int b)
//   { return a + b; };

//   std::cout << do_math(1, 2, wrapped_function_pointer) << '\n';  // 3
//   std::cout << do_math(1, 2, wrapped_function_lambda) << '\n';   // 3
//   std::cout << do_math(1, 2, wrapped_function_simple) << '\n';   // 3
// }

//--------------------------------
// SLIDE 71
//--------------------------------
// long long factorial(int n)
// {
//   if (n <= 1)
//     return 1;                   // Base case: 0! or 1! is 1
//   return n * factorial(n - 1);  // Recursive call
// }

// int main()
// {
//   int n{};
//   std::cout << "Enter a number: ";
//   std::cin >> n;
//   std::cout << "Factorial of " << n << " is " << factorial(n) << '\n';
// }

//--------------------------------
// SLIDE 72 
//--------------------------------
// int main(int argc, char *argv[])
// {
//   std::cout << "Number of arguments: " << argc << '\n';
//   for (int i{0}; i < argc; i++)
//   {
//     std::cout << "Argument " << i << ": " << argv[i] << '\n';
//   }
// }