#include <functional>
#include <iostream>
#include <string>
#include <vector>

//----------------------------------------------------------------------
// -- SLIDE 10
//----------------------------------------------------------------------
// //function prototypes
// void print_hello();
// void print_world();

// // function definitions
// void print_world() { std::cout << "world\n"; }

// void print_hello()
// {
//   std::cout << "hello, ";
//   print_world();
// }

// int main()
// {
//   print_hello();
//   std::cout << "exit main\n";
// }

//----------------------------------------------------------------------
// -- SLIDE 11
//----------------------------------------------------------------------
// void print_hello(){
//     std::cout << "hello, ";
//     print_world();
// }

// void print_world(){
//     std::cout << "world\n";
// }

// int main(){
//     print_hello();
//     std::cout << "exit main\n";
// }

//----------------------------------------------------------------------
// -- SLIDE 12
//----------------------------------------------------------------------
// void prompt_user(){
//   std::cout << "Enter a number: ";
//   int num{};
//   std::cin >> num;
//   print_number(num);
// }

// void print_number(int number){
//   if (number > 0)
//     std::cout << "The number is: " << number << "\n";
//   else
//     prompt_user();
// }

// int main(){
//   prompt_user();
// }

//----------------------------------------------------------------------
// -- SLIDE 13
//----------------------------------------------------------------------
// // function prototypes
// void print_hello();
// void print_world();

// int main(){
//     print_hello();
//     std::cout << "exit main\n";
// }

//----------------------------------------------------------------------
// -- SLIDE 19
//----------------------------------------------------------------------
// void modify(int x) {
//     // implicit: int x{a};
//     x = x + 10;  // Modifying x will not affect the original value outside
//     this function std::cout << "Inside function, x = " << x << '\n'; // 15
// }

// int main() {
//     int a{5};
//     modify(a);
//     std::cout << "Outside function, a = " << a << '\n'; // 5
// }

//----------------------------------------------------------------------
// -- SLIDE 22
//----------------------------------------------------------------------
// void modify(int &x) {
//     // implicit: int &x{a};
//     x = x + 10;  // Modifying x will affect the original value outside this
//     function std::cout << "Inside function, x = " << x << '\n'; // 15
// }

// int main() {
//     int a{5};
//     modify(a);
//     std::cout << "Outside function, a = " << a << '\n'; // 15
// }

//----------------------------------------------------------------------
// -- SLIDE 23
//----------------------------------------------------------------------
// void modify(std::vector<int> &v) {  // Passed by reference
//     // implicit: std::vector<int> &v{numbers};
//     int n{v.back()};
//     n++;
//     v.push_back(n);
// }

// int main() {
//     std::vector<int> vect = {1, 2, 3, 4, 5};
//     modify(vect);
//     for (auto item : vect) {
//         std::cout << item << " "; // 1 2 3 4 5 6
//     }
// }

//----------------------------------------------------------------------
// -- SLIDE 25
//----------------------------------------------------------------------
// void print_vector(const std::vector<int> &v) {  // Passed by const reference
//     // implicit: const std::vector<int> &v{numbers};
//     for (int num : v) {
//         std::cout << num << " "; // 1 2 3 4 5
//     }
//     // v.push_back(100);  // This would be an error since v is const
// }

// int main() {
//     std::vector<int> vect = {1, 2, 3, 4, 5};
//     print_vector(vect);
// }

//----------------------------------------------------------------------
// -- SLIDE 26
//----------------------------------------------------------------------
// void modify(int* p) {
//     // implicit: int* p{&a};
//     *p = *p + 10;
// }

// int main() {
//     int a{5};
//     modify(&a);
//     std::cout << a << '\n'; // 15
// }

//----------------------------------------------------------------------
// -- SLIDE 29
//----------------------------------------------------------------------
// void count_calls() {
//     static int count{0}; // static variable
//     count++;
//     std::cout << count << " times\n";
// }

// int main() {
//     count_calls(); // 1 times;
//     count_calls(); // 2 times;
//     count_calls(); // 3 times;
// }

//----------------------------------------------------------------------
// -- SLIDE 30
//----------------------------------------------------------------------
// int return_value(int a) {
//     return a;
//     std::cout << "a is " << a << '\n';
// }

// int main() {
//     int a{-5};
//     std::cout << return_value(a) << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 31
//----------------------------------------------------------------------
// int add(int a, int b) {
//     int c{a + b};
//     return c;
// }

// int main() {
//     int result{add(1,2)};
//     std::cout << result << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 34
//----------------------------------------------------------------------
// std::vector<int> create_vectors() {
//     std::vector<int> vect1{1,2,3};
//     std::cout << "&vec1: " << &vect1 << '\n'; //0xA
//     std::vector<int> vect2{10,20,30};
//     std::cout << "&vec2: " << &vect2 << '\n'; //0xB
//     return vect1;
// }

// int main() {
//     std::vector vect{create_vectors()};
//     std::cout << "&vect: " << &vect << '\n'; //0xA
// }

//----------------------------------------------------------------------
// -- SLIDE 35
//----------------------------------------------------------------------
// std::vector<int> create_vector1() {
//     std::vector<int> v1{1,2,3};
//     std::cout << "&v1: " << &v1 << '\n'; // 0x7ffeeb0b4a10
//     return v1;
// }

// std::vector<int> create_vector2() {
//     return std::vector<int> {1,2,3};
// }

// int main() {
//     std::vector<int> vect1{};
//     vect1 = create_vector1();
//     std::cout << "&vect1: " << &vect1 << '\n'; // 0x7ffeeb0b4a30

//     std::vector<int> vect2{};
//     vect2 = create_vector2();
// }

//----------------------------------------------------------------------
// -- SLIDE 38
//----------------------------------------------------------------------
// int& f() {
//   static int var{1};
//   std::cout << var << '\n';
//   return var;
// }

// // usage
// int main() {
//   f() = 5;          // 1
//   auto &ref = f();  // 5
//   ref = 10;
//   f();              // 10
// }

//----------------------------------------------------------------------
// -- SLIDE 39
//----------------------------------------------------------------------
// int* f() {
//   static int a{1};
//   std::cout << a << '\n';
//   return &a;
// }

// // usage
// int main() {
//     *f() = 5;       // 1
//     int* ptr = f(); // 5
//     *ptr = 10;
//     f();            // 10
// }

//----------------------------------------------------------------------
// -- SLIDE 41
//----------------------------------------------------------------------
// int add(int a, int b) {return a + b;}
// double add(double a, double b) {return a + b;}
// double add(int a, double b) {return a + b;}
// double add(double a, int b) {return a + b;}
// double add(double a, double b, double c) {return a + b + c;}

// int main() {
//   std::cout << add(2, 3) << '\n';            //add(int, int)
//   std::cout << add(2, 3.5) << '\n';          //add(int, double)
//   std::cout << add(2.5, 3) << '\n';          //add(double, int)
//   std::cout << add(2.5, 3.2) << '\n';        //add(double, double)
//   std::cout << add(2.5, 3.2, 4.75) << '\n';  //add(double, double, double)
// }

//----------------------------------------------------------------------
// -- SLIDE 43
//----------------------------------------------------------------------
// double return_value(double a) {
//   return a;
// }

// int return_value(double a) { //@\codeerror@: redefinition of 'return_value'
//   return a;
// }

// int main() {
//   std::cout << return_value(2) << '\n';
//   std::cout << return_value(2.5) << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 44
//----------------------------------------------------------------------
// void add(int a, int b=0, int c=0){
//     std::cout << a + b + c << '\n';
// }

// int main(){
//     add(1);       // a=1, b=0, c=0
//     add(1, 2);    // a=1, b=2, c=0
//     add(1, 2, 3); // a=1, b=2, c=3
//     add();        // error: no matching function for call to 'add()'
// }

//----------------------------------------------------------------------
// -- SLIDE 45
//----------------------------------------------------------------------
// void add(int a, int b=0, int c=0);

// void add(int a, int b=0, int c=0){
//     std::cout << a + b + c << '\n';
// }

// int main(){
//     add(1, 2);    // a=1, b=2, c=0
// }

//----------------------------------------------------------------------
// -- SLIDE 46
//----------------------------------------------------------------------
// int add(int a, int b){
//   return a + b;
// }

// int add(int a, int b=0){ //error: redefinition of int add(int, int)
//   return a + b;
// }

//----------------------------------------------------------------------
// -- SLIDE 47
//----------------------------------------------------------------------
// int return_int(int a, int b=1);

// int return_int(int a, int b){
//   return a*b;
// }

// int main(){
//     std::cout << return_int(2) << '\n'; // 2
//     std::cout << return_int(2, 3) << '\n'; // 6
// }

//----------------------------------------------------------------------
// -- SLIDE 49
//----------------------------------------------------------------------
// void f(int& x, int y, int z) {
//   x += y + z;
// }

// int g(int a, int b) {
//   int result{};
//   result = a + b;
//   f(result, a, b);
//   return result;
// }

// int main() {
//   int x{10};
//   int y{20};
//   int z{};
//   z = g(x, y);
//   std::cout << z << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 54
//----------------------------------------------------------------------
// int add(int a, int b) { return a + b; }
// int multiply(int a, int b) { return a * b; }

// void print_hello() { std::cout << "hello\n"; }
// void print_world() { std::cout << "world\n"; }

// int main()
// {
//   std::function<int(int, int)> math_func;
//   math_func = add;
//   std::cout << math_func(1, 2) << '\n';

//   math_func = multiply;
//   std::cout << math_func(2, 3) << '\n';

//   std::function<void()> print_func;
//   print_func = print_hello;
//   print_func();

//   print_func = print_world;
//   print_func();
// }

//----------------------------------------------------------------------
// -- SLIDE 57
//----------------------------------------------------------------------
// int add(int a, int b) { return a + b; }
// int multiply(int a, int b) { return a * b; }
// double divide(double a, double b) { return a / b; }

// int main()
// {
//   // declare a function pointer named my_ptr that can point to a function that
//   // takes two int parameters and returns an int
//   int (*my_ptr)(int, int);

//   // assign the address of the add function to my_ptr
//   my_ptr = add;
//   /*
//   call add(1, 2) through a pointer to add()
//   and store the result in result
//   */
//   int result{my_ptr(1, 2)};
//   std::cout << result << '\n';

//   // assign the address of the multiply function to my_ptr
//   my_ptr = multiply;
//   /*
//   call multiply(2, 3) through a pointer to multiply()
//   and store the result in result
//   */
//   result = my_ptr(2, 3);  // call multiply(2, 3) through a pointer
//   std::cout << result << '\n';
//   /*
//   error: cannot convert 'double (*)(double, double)' to 'int (*)(int, int)'
//   in assignment
//   */
//   my_ptr = divide;  
//   result = my_ptr(5.3, 2.5);
//   std::cout << result << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 58
//----------------------------------------------------------------------
// int add(int a, int b) { return a + b; }

// // higher-order function
// int do_math(int a, int b, std::function<int(int, int)> math_func)
// {
//   return math_func(a, b);
// }

// int main()
// {
//   // raw function pointer to 'add'
//   int (*ptr_add)(int, int) = add;
//   // using std::function to wrap the raw function pointer
//   std::function<int(int, int)> wrapped_function = ptr_add;
//   // calling the wrapped function
//   auto result = do_math(1, 2, wrapped_function);
//   std::cout << result << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 62
//----------------------------------------------------------------------

// int main(){
// //   []()->void { std::cout << "hello, world\n"; }();
// // auto print_hello_world = []() { std::cout << "hello, world\n"; };
// // print_hello_world();

// // std::cout << [](int a, int b)->int { return a + b; }(1, 2) << '\n';
// // auto sum = [](int a, int b) -> int { return a + b; };
// // std::cout << sum(1, 2) << '\n';

// int x{10};
// int y{20};
// // std::cout << [x, y]() { return x + y; }() << '\n';
// // auto sum = [x, y]() { return x + y; };
// // std::cout << sum() << '\n';
// [=, &y]() { y = 3*x; }();
// std::cout << y << '\n';

// // auto sum = [x, y]() { return x + y; };
// // std::cout << sum() << '\n';
// }

//----------------------------------------------------------------------
// -- SLIDE 63
//----------------------------------------------------------------------

// // higher-order function
// int do_math(int a, int b, const std::function<int(int, int)>& math_func)
// {
//   return math_func(a, b);
// }

// int main()
// {
//   // lambda for addition
//   auto add = [](int a, int b) { return a + b; };
//   // lambda for multiplication
//   auto multiply = [](int a, int b) { return a * b; };

//   int result = do_math(1, 2, add);
//   std::cout << result << '\n';  // 3

//   result = do_math(2, 3, multiply);
//   std::cout << result << '\n';  // 6
// }

//----------------------------------------------------------------------
// -- SLIDE 67
//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
// -- SLIDE 69
//----------------------------------------------------------------------
// int main(int argc, char *argv[])
// {
//   std::cout << "Number of arguments: " << argc << '\n';
//   for (int i{0}; i < argc; i++)
//   {
//     std::cout << "Argument " << i << ": " << argv[i] << '\n';
//   }
// }
