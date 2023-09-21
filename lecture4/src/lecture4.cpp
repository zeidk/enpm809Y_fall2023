#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <typeinfo>

using namespace std::literals::string_literals;

int main()
{
  // ------------------
  // -- SLIDE 16 --
  // ------------------
  // std::cout << "hello, world\n";
  // auto my_string{"hello, world\n"};
  // std::cout << typeid(my_string).name() << '\n';

  // ------------------
  // -- SLIDE 20 --
  // ------------------
  // std::string s0("Initial string"); // initialized from a C string

  // std::string s1;                                   // empty string
  // std::string s2(s0);                               // initialized from another string
  // std::string s3(s0, 8, 3);                         // "str"
  // std::string s4("Another character sequence", 12); // "Another char"
  // std::string s5a(10, 'x');                         // "xxxxxxxxxx"
  // std::string s5b(10, 42);                          // "**********"
  // std::string s6(s0.begin(), s0.begin() + 7);       // "Initial"

  // ------------------
  // -- SLIDE 21 --
  // ------------------
  // auto greeting1{"hello"};       // C string
  // auto greeting2{"hello"s};      // C++ string
  // std::cout << "hello" << '\n'; // C literal
  // std::cout << "hello"s << '\n'; // C++ literal

  // ------------------
  // -- SLIDE 23 --
  // ------------------
  // std::string my_string{"Life is so good"};
  // std::cout << my_string.capacity() << '\n';
  // my_string = "Life is so good!";
  // std::cout << my_string.capacity() << '\n';

  // ------------------
  // -- SLIDE 25 --
  // ------------------
  // std::string s1{"Hello"};
  // std::string s2{"Hello Beautiful World"};
  // std::cout << sizeof(s1) << '\n';
  // std::cout << sizeof(s2) << '\n';

  // ------------------
  // -- SLIDE 26 --
  // ------------------
  // std::string greeting{"hello"};
  // std::cout << greeting.length() << '\n'; // 5
  // // or
  // std::cout << greeting.size() << '\n';   // 5

  // ------------------
  // -- SLIDE 28 --
  // ------------------
  // // initialization
  // std::string quote{"Just a flesh wound"};

  // // access characters
  // std::cout << quote.front() << '\n'; // return a ref to 1st character
  // quote.front() = 'j';                // modify the 1st character
  // std::cout << quote[0] << '\n';      // return the 1st character
  // std::cout << quote[5] << '\n';      // return the 6th character
  // std::cout << quote.at(5) << '\n';   // return the 6th character
  // std::cout << quote.back() << '\n';  // return a ref to the last character
  // quote.back() = 'D';                 // modify the last character
  // std::cout << quote.back() << '\n';
  // quote[6] = 'A';    // modify the 7th character
  // quote.at(6) = 'a'; // modify the 7th character

  // ------------------
  // -- SLIDE 29 --
  // ------------------
  // std::string greeting{"Hi"};
  // std::cout << greeting[2] << '\n'; //UB

  // ------------------
  // -- SLIDE 30 --
  // ------------------
  // std::string greeting{"Hi"};
  // std::cout << greeting.at(2) << '\n'; // error

  // ------------------
  // -- SLIDE 32 --
  // ------------------
  // std::string quote{"Just a flesh wound!"};
  // /*
  //     write a for loop to print each character of the string
  // */

  // ------------------
  // -- SLIDE 34 --
  // ------------------
  // std::string quote{"Just a flesh wound!"};

  // for (char c : quote)
  // {
  //   std::cout << c << '\n';
  // }

  // ------------------
  // -- SLIDE 36 --
  // ------------------
  // std::string greeting{"Hi"};
  // for (auto it{greeting.begin()}; it != greeting.end(); ++it)
  //   std::cout << *it << '\n';

  // ------------------
  // -- SLIDE 37 --
  // ------------------
  // std::cout << "Enter your full name: "; // e.g., John Doe
  // std::string name{};
  // std::cin >> name; // John

  // std::cout << "Enter your student id: "; // e.g., 123223LUJ
  // std::string student_id{};
  // std::cin >> student_id; // Doe

  // std::cout << "Name: " << name << ", ID: " << student_id << '\n';

  // ------------------
  // -- SLIDE 38 --
  // ------------------
  // std::cout << "Enter your full name: ";
  // std::string name{};
  // std::getline(std::cin >> std::ws, name);

  // std::cout << "Enter your student id: ";
  // std::string student_id{};
  // std::getline(std::cin >> std::ws, student_id);

  // std::cout << "Name: " << name << ", ID: " << student_id << '\n';

  // ------------------
  // -- SLIDE 39 --
  // ------------------
  // std::string s{"Hello"};
  // s += " World"; // append a string
  // s += '!';      // append a character
  // std::cout << s << '\n';

  // std::string s1{"Hello"};
  // std::string s2{"World"};
  // std::string s3{s1 + " " + s2};
  // std::cout << s3 << '\n';

  // std::string s4{"Hello"};
  // s4.append(" World!");
  // std::cout << s4 << '\n';

  // std::string s5{"Hello"};
  // s5.push_back('!');
  // std::cout << s5 << '\n';

  // ------------------
  // -- SLIDE 40 --
  // ------------------
  // std::string s1{"Hello World"};
  // std::string s2{"Big "};
  // s1.insert(6, s2); // Inserts at position 6
  // std::cout << s1 << '\n';

  // std::string s1 = "Hello World";
  // std::string s2 = "Wonderful Big Day";
  // s1.insert(6, s2, 10, 4); // Inserts "Big" starting from position 10 of s2 and taking 4 characters
  // std::cout << s1 << '\n';

  // std::string s1 = "Hello World";
  // std::string s2 = "Beautiful ";
  // s1.insert(s1.begin() + 6, s2.begin(), s2.end());
  // std::cout << s1 << '\n';

  // ------------------
  // -- SLIDE 41 --
  // ------------------
  // std::string s{"Hello World"};
  // s.erase(s.size() - 6, 6); // remove 6 characters starting from index 5
  // std::cout << s << '\n';

  // std::string s{"Hello World"};
  // s.erase(s.begin() + 6, s.end());
  // std::cout << s << '\n';

  // std::string s = "Hello";
  // s.erase(4);
  // std::cout << s << '\n';

  // std::string s{"Hello World"};
  // s.clear();
  // std::cout << s << '\n';

  // std::string s{"Hello"};
  // s.pop_back();
  // std::cout << s << '\n';

  // ------------------
  // -- SLIDE 43 --
  // ------------------
  // std::string name1{"John Doe"};
  // std::string name2{name1};      // A copy is made
  // std::string_view name3{name1}; // A snapshot is taken but no copy is made

  // std::cout << "name1: " << name1 << '\n'; // John Doe
  // std::cout << "name2: " << name2 << '\n'; // John Doe
  // std::cout << "name3: " << name3 << '\n'; // John Doe

  // ------------------
  // -- SLIDE 45 --
  // ------------------
  // std::string name1{"John Doe"};
  // std::string name2{name1};
  // std::string_view name3{name1};

  // std::cout << "name1: " << name1 << '\n'; // John Doe
  // std::cout << "name2: " << name2 << '\n'; // John Doe
  // std::cout << "name3: " << name3 << '\n'; // John Doe

  // name1 = "Robert Smith";

  // std::cout << "\nname1: " << name1 << '\n'; // Robert Smith
  // std::cout << "name2: " << name2 << '\n';   // John Doe
  // std::cout << "name3: " << name3 << '\n';   // Robert S

  // name3.remove_prefix(1); // removes 1 character from the beginning
  // name3.remove_suffix(1); // removes 1 character from the end

  // std::cout << "\nname1: " << name1 << '\n'; // Robert Smith
  // std::cout << "name2: " << name2 << '\n';   // John Doe
  // std::cout << "name3: " << name3 << '\n';   // obert

  // ------------------
  // -- SLIDE 47 --
  // ------------------
  // //------ SSO: STACK Allocation
  // std::string s(3, 'A');             // "AAA"
  // std::cout << s.size() << '\n';     // 3
  // std::cout << s.capacity() << '\n'; // 15

  // //------- HEAP allocation
  // s.assign(16, 'B');                 // BBBBBBBBBBBBBBBB
  // std::cout << s.size() << '\n';     // 16
  // std::cout << s.capacity() << '\n'; // 30 ???
  // s.assign(31, 'C');                 // CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
  // std::cout << s.size() << '\n';     // 31
  // std::cout << s.capacity() << '\n'; // 60 ???

  // ------------------
  // -- SLIDE 50 --
  // ------------------
  // std::string full_name;
  // full_name.reserve(100); // allocate memory for 100 items

  // std::cout << "Enter your first name: "; // Albus
  // std::string first_name;
  // std::cin >> first_name;

  // std::cout << "Enter your middle name: "; // Percival
  // std::string middle_name;
  // std::cin >> middle_name;

  // std::cout << "Enter your last name: "; // Dumbledore
  // std::string last_name;
  // std::cin >> last_name;

  // // only the first character is kept
  // middle_name.resize(1);

  // // capacity is now equal to size
  // full_name = first_name + " " + middle_name + ". " + last_name;
  // full_name.shrink_to_fit();

  // std::cout << full_name << '\n'; // Albus P. Dumbledore

  // ------------------
  // -- SLIDE 58 --
  // ------------------
  // std::array<int, 5> a1{1, 2, 3, 4, 5};              // [1, 2, 3, 4, 5]
  // std::array<int, 10> a2{1, 2, 3, 4, 5, 6, 7, 8, 9}; // [1, 2, 3, 4, 5, 6, 7, 8, 9]

  // std::cout << sizeof(a1) << '\n';
  // std::cout << sizeof(a2) << '\n';

  // ------------------
  // -- SLIDE 62-a --
  // ------------------
  // // zero initialization
  // int a1[2]{}; // [0, 0]
  // // explicit initialization
  // int a2[2]{1, 2};
  // // partial initialization
  // int a3[2]{1}; // [1, 0]
  // // size deduction
  // int a4[]{1, 2};

  // // fill with explicit initialization
  // // up to but not including
  // int a5[3]{};              // [0, 0, 0]
  // std::fill(a5, a5 + 2, 3); //[3, 3, 0]

  // // fill with partial initialization
  // // up to but not including
  // int a6[3]{};              // [0, 0, 0]
  // std::fill(a6, a6 + 2, 1); //[1, 1, 0]

  // ------------------
  // -- SLIDE 62-b --
  // ------------------
  // // zero initialization
  // std::array<int, 2> a1{}; // [0, 0]
  // // explicit initialization
  // std::array<int, 2> a2 = {1, 2};
  // // partial initialization
  // std::array<int, 2> a3 = {1}; // [1, 0]

  // // fill with explicit initialization
  // // up to but not including
  // std::array<int, 2> a4;
  // std::fill(a4.begin(), a4.end(), 3); //[3, 3]

  // // fill with partial initialization
  // // up to but not including
  // std::array<int, 3> a5{};
  // std::fill(a5.begin(), a5.begin() + 2, 1); //[1, 1, 0]

  // ------------------
  // -- SLIDE 63 --
  // ------------------
  // constexpr size_t length1{3};
  // size_t length2{3};

  // // C-style array
  // int a1[3]{};       // ok: 3 is a compile-time constant
  // int a2[length1]{}; // ok: length1 is a compile-time constant
  // int a3[length2]{}; // error: length2 is not a compile-time constant

  // // C++ style array
  // std::array<int, 3> a4{};       // ok: 3 is a compile-time constant
  // std::array<int, length1> a5{}; // ok: length1 is a compile-time constant
  // std::array<int, length2> a6{}; // error: length2 is not a compile-time constant

  // ------------------
  // -- SLIDE 66-a --
  // ------------------
  // constexpr size_t length{3};

  // int a1[length]{1, 2, 3};
  // std::cout << a1[0] << '\n'; // 1
  // a1[0] = 10;                 // [10, 2, 3]

  // // regular for loop
  // for (size_t i{0}; i < length; ++i)
  //   std::cout << a1[i] << ' ';
  // std::cout << '\n';

  // // range-based for loop
  // for (const auto &item : a1)
  //   std::cout << item << ' ';
  // std::cout << '\n';

  // ------------------
  // -- SLIDE 66-b --
  // ------------------
  // constexpr size_t length{3};

  // std::array<int, length> a2{10, 20, 30};
  // std::cout << a2.at(0) << '\n';   // 10
  // std::cout << a2.empty() << '\n'; // 0 (false)
  // std::cout << a2.size() << '\n';  // 3
  // std::cout << a2.front() << '\n'; // 10
  // std::cout << a2.back() << '\n';  // 30
  // a2.at(0) = 100;                  // [100, 20, 30]

  // // regular for loop
  // for (size_t i{0}; i < length; ++i)
  //   std::cout << a2.at(i) << ' ';
  // std::cout << '\n';

  // // range-based for loop
  // for (const auto &item : a2)
  //   std::cout << item << ' ';
  // std::cout << '\n';

  // a2.fill(0); // [0, 0, 0]

  // ------------------
  // -- SLIDE 70 --
  // ------------------
  // int numbers[3][2][3]{
  //     {{1, 2, 3}, {4, 5, 6}},
  //     {{7, 8, 9}, {10, 11, 12}},
  //     {{13, 14, 15}, {16, 17, 18}}};

  // std::array<std::array<std::array<int, 3>, 2>, 3> numbers{
  //     {{{{1, 2, 3}, {4, 5, 6}}},
  //      {{{7, 8, 9}, {10, 11, 12}}},
  //      {{{13, 14, 15}, {16, 17, 18}}}}};

  // for loop to display each element of numbers
  // for (int i{0}; i < 3; ++i)
  // {
  //   for (int j{0}; j < 2; ++j)
  //   {
  //     for (int k{0}; k < 3; ++k)
  //     {
  //       std::cout << numbers[i][j][k] << ' ';
  //     }
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';
  // }

  // range-based for loop to display each element of numbers
  // for (const auto &array2D : numbers)
  // {
  //   for (const auto &array1D : array2D)
  //   {
  //     for (const auto &element : array1D)
  //     {
  //       std::cout << element << ' ';
  //     }
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';
  // }

  // ------------------
  // -- SLIDE 75 --
  // ------------------
  // std::vector<int> vec1 = {1, 2, 3};
  // std::vector<int> vec2 = {1, 2, 3, 4, 5};

  // std::cout << sizeof(vec1) << '\n';
  // std::cout << sizeof(vec2) << '\n';

  // ------------------
  // -- SLIDE 76 --
  // ------------------
  // std::vector<int> v1{-1, 3, 5}; // initialization with explicit values
  // std::vector<int> v2{};         // zero initialization
  // v2 = v1;                       // copy items of v1 into v2
  // auto v3{v1};                   // initialization from an existing vector

  // ------------------
  // -- SLIDE 77 --
  // ------------------
  // std::vector<int> numbers{-1, 3, 5, -9}; // initialization with 4 items

  // std::cout << numbers.front() << '\n'; // -1
  // std::cout << numbers.back() << '\n';  // -9

  // // indexing operator (no bounds check)
  // numbers[0] = -2;                 // [-2, 3, 5, -9]
  // std::cout << numbers[0] << '\n'; // -2
  // // at() method
  // numbers.at(0) = 1;                  // [1, 3, 5, -9]
  // std::cout << numbers.at(3) << '\n'; // 4th item - bounds check

  // // regular for loop
  // for (size_t i{0}; i < numbers.size(); ++i)
  //   numbers[i] = 0;
  // std::cout << '\n';

  // // ranged-base for loop
  // for (auto &item : numbers)
  //   item = 1;
  // std::cout << '\n';

  // numbers.assign({1, 2, 3, 4}); // replace entire content with new values

  // ------------------
  // -- SLIDE 78 --
  // ------------------
  // std::vector<std::string> fruits = {"apple"};

  // //=== INSERTION ===
  // //push_back(): Adds an element to the end.
  // fruits.push_back("cherry"); // fruits: {"apple", "cherry"}
  // // emplace_back() : Constructs and adds an element to the end.
  // fruits.emplace_back("pear"); // fruits: {"apple", "cherry", "pear"}
  // // insert(): Inserts an element before the specified position.
  // fruits.insert(fruits.begin() + 2, "kiwi"); // fruits: {"apple", "cherry", "kiwi", "pear"}
  // // emplace(): Constructs and inserts an element before the specified position.
  // fruits.emplace(fruits.begin() + 1, "orange"); // fruits: {"apple", "orange", "cherry", "kiwi", "pear"}

  // //=== DELETION ===
  // // pop_back(): Removes the last element.
  // fruits.pop_back(); // fruits: {"apple", "orange", "cherry", "kiwi"}
  // // erase(): Removes the specified elements.
  // fruits.erase(fruits.begin() + 1); // fruits: {"apple", "cherry", "kiwi"}
  // // erase() -- (iterator position)
  // fruits.erase(fruits.begin() + 1); // fruits: {"apple", "kiwi"}
  // // erase() -- (iterator range)
  // fruits.erase(fruits.begin() + 1, fruits.end()); // fruits: {"apple"}
  // // clear(): Removes all elements.
  // fruits.clear(); // fruits: {}
}