#include <iostream>
#include "header.h"

// Example1 - motivation
// struct SomeStruct {
//      int super_static_vstaticariable = 10;     // compile error - ODR
// };
// int SomeStruct::super_static_variable = 10; // should be in cpp

struct SomeStruct2 {
    static inline int super_static_variable = 42;
};

struct SomeStruct3 {
    static int super_static_variable;
};
inline int SomeStruct3::super_static_variable = 84;


int main() {

    // std::cout << SomeStruct::super_static_variable << std::endl;
    
    std::cout << SomeStruct2::super_static_variable << std::endl;

    std::cout << SomeStruct3::super_static_variable << std::endl;

    return 0;
}