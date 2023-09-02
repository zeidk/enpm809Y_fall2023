#include <iostream>
#include <iomanip> // for output manipulator std::setprecision()
#include <climits> // for integer limits
#include <cfloat> // for floating point limits

int main()
{

    //------------------------------------------
    // SLIDE 10
    //------------------------------------------

    float f_var;

    std::cout << sizeof(int) << "\n";    // 4 bytes on my machine
    std::cout << sizeof(double) << "\n"; // 8 bytes on my machine
    std::cout << sizeof(f_var) << "\n";  // 4 bytes on my machine
    std::cout << sizeof f_var << "\n";   // 4 byteson my machine

    //------------------------------------------
    // SLIDE 12
    //------------------------------------------
    // int number1 = 1'334'872'343;
    // int number2 = 13'34'87'23'43;
    // int number3 = 1'33'4872'343;
    // int number4 = 1334'872'34'3;
    // std::cout << number1 << "\n"; // 1334872343
    // std::cout << number2 << "\n"; // 1334872343
    // std::cout << number3 << "\n"; // 1334872343
    // std::cout << number4 << "\n"; // 1334872343

    //------------------------------------------
    // SLIDE 15
    //------------------------------------------
    // std::cout << "Range for [signed] char: [" << SCHAR_MIN << "," << SCHAR_MAX << "], Width: " << SCHAR_WIDTH << " bits\n";
    // std::cout << "Range for [unsigned] char: [0," << UCHAR_MAX << "], Width: " << UCHAR_WIDTH << " bits\n";
    // std::cout << "Range for [signed] int: [" << INT_MIN << "," << INT_MAX << "], Width: " << INT_WIDTH << " bits\n";
    // std::cout << "Range for unsigned int: [0," << UINT_MAX << "], Width: " << UINT_WIDTH << " bits\n";
    // std::cout << "Range for [signed] short [int]: [" << SHRT_MIN << "," << SHRT_MAX << "], Width: " << SHRT_WIDTH << " bits\n";
    // std::cout << "Range for unsigned short [int]: [0," << USHRT_MAX << "], Width: " << USHRT_WIDTH << " bits\n";
    // std::cout << "Range for [signed] long [int]: [" << LONG_MIN << "," << LONG_MAX << "], Width: " << LONG_WIDTH << " bits\n";
    // std::cout << "Range for unsigned long [int]: [0,"  << ULONG_MAX << "], Width: " << ULONG_WIDTH << " bits\n";
    // std::cout << "Range for [signed] long long [int]: [" << LLONG_MIN << "," << LLONG_MAX << "], Width: " << LLONG_WIDTH << " bits\n";
    // std::cout << "Range for unsigned long long [int]: [0," << ULLONG_MAX << "], Width: " << ULLONG_WIDTH << " bits\n";

    //------------------------------------------
    // SLIDE 21
    //------------------------------------------
    // char char1 = 'a';
    // char char2 = 97;
    // std::cout << char1 << '\n'; // a
    // std::cout << char2 << '\n'; // a

    //------------------------------------------
    // SLIDE 22
    //------------------------------------------
    // std::cout << "Minimum value for char: " << CHAR_MIN << '\n';

    //------------------------------------------
    // SLIDE 23
    //------------------------------------------
    // char var_char = 'a';
    // std::cout << var_char << '\n';                   // a
    // std::cout << static_cast<int>(var_char) << '\n'; // 97
    // std::cout << var_char << '\n';                   // a

    //------------------------------------------
    // SLIDE 24
    //------------------------------------------
    // std::cout << "First\v \\line\nSecond\t line\n";

    //------------------------------------------
    // SLIDE 27
    //------------------------------------------
    // signed char a = static_cast<char>(100); // maximum range number: 255
    // signed char b = static_cast<char>(200); // maximum range number: 255
    // signed char c = a + b;
    // std::cout << static_cast<int>(c) << '\n'; // 44

    //------------------------------------------
    // SLIDE 33
    //------------------------------------------
    // std::cout << 1f << "\n";   // compiler error
    // std::cout << 1.0f << "\n"; // OK

    //------------------------------------------
    // SLIDE 34
    //------------------------------------------
    // std::cout << 8.34234356f << '\n';      // 8.34234
    // std::cout << 834.234356f << '\n';      // 834.234
    // std::cout << 834234.356f << '\n';      // 834234
    // std::cout << 8342343.56f << '\n';      // 8.34234e+06
    // std::cout << 0.0000834234356f << '\n'; // 8.34234e-05

    //------------------------------------------
    // SLIDE 35
    //------------------------------------------
    // std::cout << std::setprecision(9);   // show 9 digits of precision
    // std::cout << 0.33333333333f << '\n'; // 0.333333343

    //------------------------------------------
    // SLIDE 36
    //------------------------------------------
    // double with 22 digits
    // std::cout << 8.3642343534322323232322 << '\n'; // output: 8.36423 (only 6 digits)
    // std::cout << std::setprecision(15) << '\n';
    // std::cout << 8.3642343534322323232322 << '\n'; // output: 8.36423435343223 (15 digits)

    //------------------------------------------
    // SLIDE 39
    //------------------------------------------
    // std::cout << sizeof(long double) << '\n'; // 16 bits on my machine
    // std::cout << sizeof(double) << '\n';      // 8 bits on my machine

    //------------------------------------------
    // SLIDE 40
    //------------------------------------------
    // bool is_today_sunny = true;
    // bool is_today_cloudy = false;
    // std::cout << is_today_sunny << '\n';  // 1
    // std::cout << is_today_cloudy << '\n'; // 0

    // bool is_today_sunny = true;
    // bool is_today_cloudy = false;
    // std::cout << std::boolalpha << is_today_sunny << "\n";  // true
    // std::cout << std::boolalpha << true << "\n";            // true
    // std::cout << std::noboolalpha << true << "\n";          // 1
    // std::cout << std::boolalpha << is_today_cloudy << "\n"; // false
    // std::cout << std::boolalpha << false << "\n";           // false
    // std::cout << std::noboolalpha << false << "\n";         // 0
}