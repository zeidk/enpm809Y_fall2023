#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <typeinfo>

using namespace std::literals::string_literals;

int main()
{
  // -- SLIDE 15 --
  // std::cout << "hello, world\n";
  // auto my_string{"hello, world\n"};
  // std::cout << typeid(my_string).name() << '\n';

  // -- SLIDE 19 --
  // std::string s0("Initial string"); // initialized from a C string

  // std::string s1;                                   // empty string
  // std::cout << s1 << '\n';
  // std::string s2(s0);                               // initialized from another string
  // std::cout << s2 << '\n';
  // std::string s3(s0, 8, 3);                         // "str"
  // std::cout << s3 << '\n';
  // std::string s4("Another character sequence", 12); // "Another char"
  // std::cout << s4 << '\n';
  // std::string s5a(10, 'x');                         // "xxxxxxxxxx"
  // std::cout << s5a << '\n';
  // std::string s5b(10, 42);                          // "**********"
  // std::cout << s5b << '\n';
  // std::string s6(s0.begin(), s0.begin() + 7);       // "Initial"
  // std::cout << s6 << '\n';

  // -- SLIDE 20 --
  // auto greeting1{"hello"};
  // std::cout << typeid(greeting1).name() << '\n';
  // auto greeting2{"hello"s};
  // std::cout << typeid(greeting2).name() << '\n';
  // std::cout << "hello"s << '\n';

  // -- SLIDE 25 --
  // // initialization
  // std::string quote{"Just a flesh wound"};

  // // access characters
  // std::cout << quote.front() << '\n'; // return the first character
  // quote.front() = 'j';                // modify the first character
  // std::cout << quote[0] << '\n';      // return the first character
  // std::cout << quote[5] << '\n';      // return the sixth character
  // std::cout << quote.at(5) << '\n';   // return the sixth character
  // std::cout << quote.back() << '\n';  // return the last character
  // quote.back() = 'D';                 // modify the last character
  // std::cout << quote.back() << '\n';
  // quote[6] = 'A';                     // modify the seventh character
  // quote.at(6) = 'a';                  // modify the seventh character

  // -- SLIDE 26 --
  // std::string greeting{"Hi"};
  // std::cout << greeting[2] << '\n'; // UB

  // -- SLIDE 27 --
  // std::string greeting{"Hi"};
  // std::cout << greeting.at(2) << '\n'; // runtime error

  // -- SLIDE 33 --
  // std::string txt{"Hi"};
  // for (auto it{txt.begin()}; it != txt.end(); ++it)
  //     std::cout << *it << '\n';

  // -- SLIDE 34 --
  // std::cout << "Enter your full name: "; // e.g., John Doe
  // std::string name{};
  // std::cin >> name; // John

  // std::cout << "Enter your student id: "; // e.g., 123223LUJ
  // std::string student_id{};
  // std::cin >> student_id; // Doe

  // std::cout << "Name: " << name << ", ID: " << student_id << '\n';

  // -- SLIDE 35 --
  // std::cout << "Enter your full name: ";
  // std::string name{};
  // std::getline(std::cin >> std::ws, name);

  // std::cout << "Enter your student id: ";
  // std::string student_id{};
  // std::getline(std::cin >> std::ws, student_id);

  // std::cout << "Name: " << name << ", ID: " << student_id << '\n';

  // -- SLIDE 36 --
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

  // -- SLIDE 37 --
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

  //-- SLIDE 38 --
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

  // -- SLIDE 40 --
  // std::string full_name{"John Doe"};

  // // get first name using white space as a delimiter
  // std::string first = full_name.substr(0, full_name.find(" "));
  // // get last name using white space as a delimiter
  // std::string last = full_name.substr(full_name.find(" ") + 1, full_name.length());

  // // print the first and last name
  // std::cout << "First name: " << first << ", Last name: " << last << "\n";

  // // print memory allocated for all std::string variables
  // std::cout << sizeof(full_name) + sizeof(first) + sizeof(last) << '\n';

  // -- SLIDE 41 --
  // std::string_view full_name{"John Doe"};

  // // get first name using white space as a delimiter
  // std::string_view first = full_name.substr(0, full_name.find(" "));
  // // get last name using white space as a delimiter
  // std::string_view last = full_name.substr(full_name.find(" ") + 1, full_name.length());

  // // print the first and last name
  // std::cout << "First name: " << first << ", Last name: " << last << "\n";

  // // print memory allocated for all std::string variables
  // std::cout << sizeof(full_name) + sizeof(first) + sizeof(last) << '\n';

  // -- SLIDE 43 --
  //------ SSO: STACK Allocation
  // std::string s(3, 'A');             // "AAA"
  // std::cout << s.size() << '\n';     // 3
  // std::cout << s.capacity() << '\n'; // 15

  // //------- HEAP allocation
  // s.assign(16, 'B');                 // BBBBBBBBBBBBBBBB
  // std::cout << s.size() << '\n';     // 16
  // std::cout << s.capacity() << '\n'; // 30
  // s.assign(31, 'C');                 // CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
  // std::cout << s.size() << '\n';     // 31
  // std::cout << s.capacity() << '\n'; // 60

  //-- SLIDE 46 --
  // std::string full_name;
  // full_name.reserve(100); // allocate memory for 100 items
  // std::cout << "Capacity: " << full_name.capacity() << '\n';

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
  // std::cout << "Middle Capacity: " << middle_name.capacity() << '\n';

  // // capacity is now equal to size
  // full_name = first_name + " " + middle_name + ". " + last_name;
  // full_name.shrink_to_fit();
  // std::cout << "Capacity: " << full_name.capacity() << '\n';
  // std::cout << "Size: " << full_name.size() << '\n';

  // std::cout << full_name << '\n'; // Albus P. Dumbledore

  // -- SLIDE 57 --
  // zero initialization
  // std::array<int, 2> a1{}; // [0, 0]
  // // explicit initialization
  // std::array<int, 2> a2 = {1, 2};
  // // partial initialization
  // std::array<int, 2> a3 = {1}; // [1, 0]
  // //@\emphIII{no size deduction}@

  // // fill with explicit initialization
  // // up to but not including
  // std::array<int, 2> a4;
  // std::fill(a4.begin(), a4.end(), 3); //[3, 3]

  // // fill with partial initialization
  // // up to but not including
  // std::array<int, 3> a5{};
  // std::fill(a5.begin(), a5.begin() + 2, 1); //[1, 1, 0]

  //-- SLIDE 58 --
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

  //-- SLIDE 71 --

  //=== INSERTION ===//
  // push_back(): Adds an element to the end.
  // std::vector<std::string> vec1 = {"apple", "banana"};
  // vec1.push_back("cherry"); // vec1: {"apple", "banana", "cherry"}
  // // emplace_back() : Constructs and adds an element to the end.
  // vec1.emplace_back("pear"); // vec1: {"apple", "banana", "cherry", "pear"}
  // // insert(): Inserts an element before the specified position.
  // vec1.insert(vec1.begin() + 2, "kiwi"); // vec1: {"apple", "banana", "kiwi", "cherry", "pear"}
  // // emplace(): Constructs and inserts an element before the specified position.
  // vec1.emplace(vec1.begin() + 1, "orange"); // vec1: {"apple", "orange", "banana", "kiwi", "cherry", "pear"}

  // //=== DELETION ===//
  // // pop_back(): Removes the last element.
  // vec1.pop_back(); // vec1: {"apple", "orange", "banana", "kiwi", "cherry"}
  // // erase(): Removes the specified elements.
  // vec1.erase(vec1.begin() + 1); // vec1: {"apple", "banana", "kiwi", "cherry"}
  // // erase (iterator position)
  // vec1.erase(vec1.begin() + 1); // vec1: {"apple", "kiwi", "cherry"}
  // // erase (iterator range)
  // vec1.erase(vec1.begin() + 1, vec1.end()); // vec1: {"apple"}
  // // clear(): Removes all elements.
  // vec1.clear(); // vec1: {}

  //-- SLIDE 72 --
  // std::vector<int> integers{1, 3};          // [1, 3]
  // std::cout << integers.size() << '\n';     // 2
  // std::cout << integers.capacity() << '\n'; // 2
  // integers.push_back(10);                   // [1, 3, 10]
  // std::cout << integers.size() << '\n';     // 3
  // std::cout << integers.capacity() << '\n'; // 4: capacity doubled
}