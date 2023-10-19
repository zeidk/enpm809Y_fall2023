#include "this_pointer.h"


int main() {
  DemoThis d;
  d.initialize(5).double_value().print_value();  // chaining function calls
}

