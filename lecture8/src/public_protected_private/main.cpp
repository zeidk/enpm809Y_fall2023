#include "public_protected_private/public_protected_private.h"

int main(){
    Base base;
    A public_derived;
    B protected_derived;
    C private_derived;

    std::cout << base.base_public_member << '\n';
    // std::cout << base.base_protected_member << '\n';
    // std::cout << base.base_private_member << '\n';

    std::cout << public_derived.base_public_member << '\n';
    // std::cout << public_derived.base_protected_member << '\n';
    // std::cout << public_derived.base_private_member << '\n';

    // std::cout << protected_derived.base_public_member << '\n';
    // std::cout << protected_derived.base_protected_member << '\n';
    // std::cout << protected_derived.base_private_member << '\n';

    // std::cout << private_derived.base_public_member << '\n';
    // std::cout << private_derived.base_protected_member << '\n';
    // std::cout << private_derived.base_private_member << '\n';
}