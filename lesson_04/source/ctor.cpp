#include "pretty.h"

#include <iostream>
#include <string>

struct foo {
    foo() { 
        std::cout << __PRETTY_FUNCTION__ << std::endl; 
    };

    foo(int) : foo{} { 
        std::cout << __PRETTY_FUNCTION__ << std::endl; 
    };

    foo(char *) : foo{} { 
        std::cout << __PRETTY_FUNCTION__ << std::endl; 
    };
};

int main(int, char *[]) {
    foo f{};

    std::cout << "next..." << std::endl;

    foo g{"42"};

    return 0;
}