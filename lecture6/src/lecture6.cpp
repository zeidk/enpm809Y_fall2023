#include <cassert>
#include <iostream>
#include <memory>

void display(std::unique_ptr<int> ptr);
void sink(std::unique_ptr<int> ptr);
void sink2(std::shared_ptr<int> ptr);
void reseat(std::unique_ptr<int>& ptr);
void reseat2(std::shared_ptr<int>& ptr);
std::unique_ptr<int> return_by_value();

int main()
{
  // ------------------------------------------------------------
  // --- SLIDE 11
  // ------------------------------------------------------------
  // std::unique_ptr<int> u_ptr1 = std::make_unique<int>(5);
  // std::unique_ptr<int> u_ptr2{u_ptr1};  // error

  // ------------------------------------------------------------
  // --- SLIDE 12
  // ------------------------------------------------------------
  // {
  //   // allocate an int on the heap
  //   auto u_ptr = std::make_unique<int>(10);
  //   std::cout << *u_ptr << '\n';  // 10
  //   *u_ptr = 20;                  // modify the resource
  //   std::cout << *u_ptr << '\n';  // 20
  //   // std::cout << u_ptr << '\n';  // error: no operator<< that takes a
  //   unique_ptr
  // }  // u_ptr is destroyed here and resource is automatically deleted

  // ------------------------------------------------------------
  // --- SLIDE 15
  // ------------------------------------------------------------
  // // allocate an int on the heap
  // auto u_ptr = std::make_unique<int>(10);
  // if (u_ptr)
  // {  // if u_ptr is not null
  //   std::cout << "The value at " << u_ptr.get() << " is " << *u_ptr << '\n';
  // }

  // // or

  // int* ptr{u_ptr.get()};  // get the stored pointer and store it in a
  // variable if (ptr) {  // if ptr is not null
  //   std::cout << "The value at " << ptr << " is " << *ptr << '\n';
  // }

  // ------------------------------------------------------------
  // --- SLIDE 17
  // ------------------------------------------------------------
  // auto u_ptr = std::make_unique<int>(10);
  // auto raw_ptr = u_ptr.release();
  // std::cout << *raw_ptr << '\n';
  // assert(u_ptr.get() == nullptr);
  // assert(u_ptr == nullptr);
  // delete raw_ptr;  // don't forget to free the memory

  // ------------------------------------------------------------
  // --- SLIDE 18
  // ------------------------------------------------------------
  // auto u_ptr = std::make_unique<int>(10);
  // u_ptr.release();

  // ------------------------------------------------------------
  // --- SLIDE 21
  // ------------------------------------------------------------
  // auto u_ptr = std::make_unique<int>(10);
  // u_ptr.reset();
  // assert(u_ptr.get() == nullptr);

  // ------------------------------------------------------------
  // --- SLIDE 22
  // ------------------------------------------------------------
  // auto u_ptr = std::make_unique<int>(10);
  // u_ptr.reset(new int(20));

  // ------------------------------------------------------------
  // --- SLIDE 24
  // ------------------------------------------------------------
  // auto u_ptr1 = std::make_unique<int>(10);
  // auto u_ptr2 = std::make_unique<int>(20);
  // u_ptr1.swap(u_ptr2);

  // ------------------------------------------------------------
  // --- SLIDE 25
  // ------------------------------------------------------------
  // auto u_ptr = std::make_unique<int>(10);
  // display(u_ptr);

  // ------------------------------------------------------------
  // --- SLIDE 28
  // ------------------------------------------------------------
  // // allocate memory for an int on the heap
  // auto u_ptr1 = std::make_unique<int>(100);
  // std::cout << "u_ptr1: " << u_ptr1.get() << '\n';  // 0x55555556aeb0

  // // transferring ownership of the resource to u_ptr2
  // auto u_ptr2{std::move(u_ptr1)};  // transfer ownership with std::move()
  // std::cout << "u_ptr2: " << u_ptr2.get() << '\n';  // 0x55555556aeb0
  // assert(u_ptr1 == nullptr);                        // u_ptr1 is null

  // // reuse u_ptr1 to allocate a new resource if needed
  // u_ptr1.reset(new int{200});
  // std::cout << u_ptr1.get() << '\n';  // 0x55555556b2e0

  // ------------------------------------------------------------
  // --- SLIDE 30
  // ------------------------------------------------------------
  // auto u_ptr = std::make_unique<int>(10);
  // sink(std::move(u_ptr));

  // ------------------------------------------------------------
  // --- SLIDE 32
  // ------------------------------------------------------------
  // std::unique_ptr<int> u_ptr = std::make_unique<int>(10);
  // std::cout << "*u_ptr: " << *u_ptr << '\n';      // 10
  // std::cout << "u_ptr: " << u_ptr.get() << '\n';  // 0x55555556b2b0
  // reseat(u_ptr);
  // std::cout << "*u_ptr1: " << *u_ptr << '\n';      // 20
  // std::cout << "u_ptr1: " << u_ptr.get() << '\n';  // 0x55555556b6e0

  // ------------------------------------------------------------
  // --- SLIDE 33
  // ------------------------------------------------------------
  // auto u_ptr{return_by_value()};
  // std::cout << *u_ptr << '\n';  // 10
  // std::cout << &u_ptr << '\n';  // 0x55555556b2b0

  // ------------------------------------------------------------
  // --- SLIDE 37
  // ------------------------------------------------------------
  // auto s_ptr1 = std::make_shared<int>(10);
  // auto s_ptr2{s_ptr1};
  // auto s_ptr3 = s_ptr2;

  // ------------------------------------------------------------
  // --- SLIDE 43
  // ------------------------------------------------------------
  // auto s_ptr1 = std::make_shared<int>(10);
  // std::cout << s_ptr1.use_count() << '\n';

  // auto s_ptr2{s_ptr1};
  // std::cout << s_ptr1.use_count() << ' ';
  // std::cout << s_ptr2.use_count() << '\n';

  // auto s_ptr3 = s_ptr2;
  // std::cout << s_ptr1.use_count() << ' ';
  // std::cout << s_ptr2.use_count() << ' ';
  // std::cout << s_ptr3.use_count() << '\n';

  // s_ptr1.reset();
  // std::cout << s_ptr1.use_count() << ' ';
  // std::cout << s_ptr2.use_count() << ' ';
  // std::cout << s_ptr3.use_count() << '\n';

  // s_ptr1.swap(s_ptr2);
  // std::cout << s_ptr1.use_count() << ' ';
  // std::cout << s_ptr2.use_count() << ' ';
  // std::cout << s_ptr3.use_count() << '\n';

  // s_ptr2.reset(new int(20));
  // std::cout << s_ptr1.use_count() << ' ';
  // std::cout << s_ptr2.use_count() << ' ';
  // std::cout << s_ptr3.use_count() << '\n';

  // ------------------------------------------------------------
  // --- SLIDE 44
  // ------------------------------------------------------------
  // auto s_ptr = std::make_shared<int>(10);
  // std::cout << s_ptr.use_count() << '\n';  // 1
  // sink2(s_ptr);
  // std::cout << s_ptr.use_count() << '\n';  // 1

  // ------------------------------------------------------------
  // --- SLIDE 45
  // ------------------------------------------------------------
  // auto s_ptr = std::make_shared<int>(10);
  // std::cout << s_ptr.use_count() << '\n';  // 1
  // reseat2(s_ptr);
  // std::cout << s_ptr.use_count() << '\n';  // 1

  // ------------------------------------------------------------
  // --- SLIDE 51
  // ------------------------------------------------------------
  // // declare an empty weak pointer
  // std::weak_ptr<int> w_ptr;
  // {
  //   auto s_ptr1 = std::make_shared<int>(10);
  //   w_ptr = s_ptr1;  // w_p now points to the resource
  //   if (auto s_ptr2 = w_ptr.lock(); s_ptr2)
  //     std::cout << "resource is " << *s_ptr2 << "\n";
  //   else
  //     std::cout << "unable to get resource\n";
  // }  // s_ptr1 goes out of scope and the resource is deleted

  // if (auto s_ptr2 = w_ptr.lock(); s_ptr2)
  //   std::cout << "resource is =" << *s_ptr2 << "\n";
  // else
  //   std::cout << "unable to get resource\n";

  // ------------------------------------------------------------
  // --- SLIDE 52
  // ------------------------------------------------------------
  // // declare an empty weak pointer
  // std::weak_ptr<int> w_ptr;
  // {
  //   auto s_ptr1 = std::make_shared<int>(10);
  //   w_ptr = s_ptr1;  // w_p now points to the resource
  //   if (!w_ptr.expired())
  //     std::cout << "resource is valid\n";
  //   else
  //     std::cout << "resource is expired\n";
  // }  // s_ptr1 goes out of scope and the resource is deleted

  // if (!w_ptr.expired())
  //   std::cout << "resource is valid\n";
  // else
  //   std::cout << "resource is expired\n";
}


//------------------------------------------------------------
// function definitions
//------------------------------------------------------------
void display(std::unique_ptr<int> ptr) { std::cout << *ptr << '\n'; }
void sink(std::unique_ptr<int> ptr) { std::cout << *ptr << '\n'; }
void reseat(std::unique_ptr<int>& ptr) { ptr.reset(new int(20)); }

std::unique_ptr<int> return_by_value()
{
  auto ptr = std::make_unique<int>(10);
  std::cout << *ptr << '\n';  // 10
  std::cout << &ptr << '\n';  // 0x55555556b2b0
  return ptr;
}

void sink2(std::shared_ptr<int> ptr)
{
  std::cout << ptr.use_count() << '\n';
}

void reseat2(std::shared_ptr<int>& ptr)
{
  std::cout << ptr.use_count() << '\n';
}
// std::unique_ptr<int> f()
// {
//   auto ptr = std::make_unique<int>(10);
//   std::cout << *ptr << '\n';  // 10
//   std::cout << &ptr << '\n';  // 0x55555556b2b0
//   return ptr;
// }

// // ------------------------------------------------------------
// // --- SLIDE 41
// // ------------------------------------------------------------
// // int main() {
// //   auto s_ptr1 = std::make_shared<int>(10);
// //   std::cout << s_ptr1.use_count() << '\n';

// //   auto s_ptr2{s_ptr1};
// //   std::cout << s_ptr1.use_count() << ' ';
// //   std::cout << s_ptr2.use_count() << '\n';

// //   auto s_ptr3 = s_ptr2;
// //   std::cout << s_ptr1.use_count() << ' ';
// //   std::cout << s_ptr2.use_count() << ' ';
// //   std::cout << s_ptr3.use_count() << '\n';

// //   s_ptr1.reset();
// //   std::cout << s_ptr1.use_count() << ' ';
// //   std::cout << s_ptr2.use_count() << ' ';
// //   std::cout << s_ptr3.use_count() << '\n';

// //   s_ptr1.swap(s_ptr2);
// //   std::cout << s_ptr1.use_count() << ' ';
// //   std::cout << s_ptr2.use_count() << ' ';
// //   std::cout << s_ptr3.use_count() << '\n';

// //   s_ptr2.reset(new int(20));
// //   std::cout << s_ptr1.use_count() << ' ';
// //   std::cout << s_ptr2.use_count() << ' ';
// //   std::cout << s_ptr3.use_count() << '\n';
// //   }

// void sink(std::shared_ptr<int>& ptr) { std::cout << ptr.use_count() << '\n';
// }

// // std::shared_ptr<int> return_shared_ptr() {
// //   auto ptr = std::make_shared<int>(10);
// //   std::cout << ptr.get() << '\n';
// //   return ptr;
// // }

// // int main() {
// //   auto s_ptr{return_shared_ptr()};
// //   std::cout << s_ptr.get() << '\n';
// //   }

// // ------------------------------------------------------------
// // --- SLIDE 42 (swap() for std::weak_ptr)
// // ------------------------------------------------------------
// // int main(){
// //   auto s_ptr1 = std::make_shared<int>(10);
// //   auto s_ptr2 = s_ptr1;
// //   // create a weak_ptr from a shared_ptr
// //   std::weak_ptr<int> w_ptr1{s_ptr1};
// //   // create a weak_ptr from another weak_ptr
// //   std::weak_ptr<int> w_ptr2{w_ptr1};
// //   std::cout << w_ptr1.use_count() << '\n';  // 2

// //   auto s_ptr3 = std::make_shared<int>(10);
// //   std::weak_ptr<int> w_ptr3{s_ptr3};
// //   std::cout << w_ptr3.use_count() << '\n';  // 1

// //   w_ptr1.swap(w_ptr3);

// //   std::cout << w_ptr1.use_count() << '\n';  // 1
// //   std::cout << w_ptr3.use_count() << '\n';  // 2
// // }

// // ------------------------------------------------------------
// // --- SLIDE 42 (expired() for std::weak_ptr)
// // ------------------------------------------------------------
// // int main()
// // {
// //   // declare an empty weak pointer
// //   std::weak_ptr<int> w_ptr;
// //   {
// //     auto s_ptr1 = std::make_shared<int>(10);
// //     w_ptr = s_ptr1;  // w_p now points to the resource
// //     if (!w_ptr.expired())
// //       std::cout << "resource is valid\n";
// //     else
// //       std::cout << "resource is expired\n";
// //   }  // s_ptr1 goes out of scope and the resource is deleted
// //   if (!w_ptr.expired())
// //     std::cout << "resource is valid\n";
// //   else
// //     std::cout << "resource is expired\n";
// // }

// // ------------------------------------------------------------
// // --- SLIDE 42 (lock() for std::weak_ptr)
// // ------------------------------------------------------------
// // int main()
// // {
// //   // declare an empty weak pointer
// //   std::weak_ptr<int> w_ptr;
// //   {
// //     auto s_ptr1 = std::make_shared<int>(10);
// //     w_ptr = s_ptr1;  // w_p now points to the resource
// //     if (auto s_ptr2 = w_ptr.lock(); s_ptr2)
// //       std::cout << "resource is " << *s_ptr2 << "\n";
// //     else
// //       std::cout << "unable to get resource\n";
// //   }  // s_ptr1 goes out of scope and the resource is deleted
// //   if (auto s_ptr2 = w_ptr.lock(); s_ptr2)
// //     std::cout << "resource is =" << *s_ptr2 << "\n";
// //   else
// //     std::cout << "unable to get resource\n";
// // }

// // ------------------------------------------------------------
// // --- SLIDE 42
// // ------------------------------------------------------------

// int main(){
//   auto s_ptr = std::make_shared<int>(10);
//   std::weak_ptr<int> w_ptr = s_ptr;
//   s_ptr.reset();
//   w_ptr.reset();
// }
