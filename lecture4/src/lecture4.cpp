#include <iostream>
#include <string>
#include <string_view>

int main()
{
  // std::string str = "The quick brown fox jumps over the lazy dog. And then runs away!!!";
  std::string str = "The quick";

  std::cout << sizeof(std::string) << '\n';

  //'string::substr' returns a new string
  // this function is memory-intensive, specially if the string is realy long
  // std::cout << str.substr(5, 15) << '\n';
  // std::cout << str << '\n';

  // The creation of string_view from the literals does not
  // require a dynamic allocation.
  std::string_view sv = str;
  std::cout << sizeof(std::string_view) << '\n';
  // std::cout << sv << '\n';

  // // string_view::substr returns a new string_view. No new memory allocated
  // std::cout << sv.substr(5, 15) << '\n';
}