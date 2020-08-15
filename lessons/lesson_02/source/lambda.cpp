#include "pretty.h"

#include <algorithm>
#include <iostream>
#include <vector>

// Motivation

struct Lookup {
    explicit Lookup(int v) : m_value{v} {

    }

    void operator()(int entry) {
        if (entry == m_value) {
            std::cout << "Found!" << std::endl;
        }
    }
private:
    int m_value;

};

void lookupAndPrint(const std::vector<int>& values, int v) {

    std::for_each(values.begin(), values.end(), Lookup{v});

}



struct Closure {
    explicit Closure(int z_) : z(z_) {};
    
    int operator()(int a, int b) {
        return  z + a + b;
    }

    int z;
};

// Basic
void example_1() {

    std::cout << "example_1" << std::endl;

    Closure cl(100);
    std::cout << cl(1, 2) << std::endl;

    std::cout << std::endl << std::endl;
}

// Easy
void example_2() {

    std::cout << "example_2" << std::endl;

    std::cout << Closure(100)(1, 2) << std::endl;

    std::cout << std::endl << std::endl;
}

struct Closure2 {
    explicit Closure2(int z_) : z(z_) {};
    
    int operator()(int a, int b) {
        return  z + a + b;
    }

    int z;
};

// Middle
void example_3() {
    std::cout << "example_3" << std::endl;
    {
        int z = 100;
        
        // Capture by value
        auto closure = [z](int a, int b) { return z + a + b; };
        std::cout << closure(1, 2) << std::endl;

        // Capture by reference
        auto closure2 = [&z](int a, int b) { return z + a + b; };
        std::cout << closure2(1, 2) << std::endl;

        // Capture all by value
        auto closure3 = [=](int a, int b) { return z + a + b; };
        std::cout << closure3(1, 2);

        // Capture all by reference
        auto closure4 = [&](int a, int b) { return z + a + b; };
        std::cout << closure4(1, 2);

        // [&z, x]
        // [x, &z]
        // [&, x]
        // [=, &z]
    }

    auto closure2 = [](int a, int b, int c) { 
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return a + b + c;
    };
    closure2(1, 2, 3);

    // lambda expression
    // [z](int a, int b) { return z + a + b; };

    // f - closure
    // auto f = [z](int a, int b) { return z + a + b; };

    // closure class
    // class lambda_x123dalsd033j1230a;

    std::cout << std::endl << std::endl;
}

// Hard
void example_4() {

    std::cout << "example_4" << std::endl;

    std::cout << [z=100](int a, int b) { return z + a + b; }(1, 2) << std::endl;

    std::vector<int> values = {0, 1, 2, 3, 3, 3, 4, 5, 6};
    std::for_each(
        values.begin(), 
        values.end(),
        [value=3](int entry) { 
            if (entry == value)
                std::cout << "Found!" << std::endl;
            }
    );

    int value = 3;
    std::for_each(
        values.begin(), 
        values.end(),
        [value](int entry) { 
            if (entry == value)
                std::cout << "Found!" << std::endl;
            }
    );

    auto closure = [z=100](int a, int b) mutable -> int { z = 150; return a + b + z; };
    closure(1, 2);

    auto closure2 = [z=100](int a, int b) mutable -> decltype(a + b) { z = 150; return a + b + z; };
    closure2(2, 3);

    auto closure3 = [](auto a, auto b) { return a + b; };
    std::cout << closure3(1.5, 2.7) << std::endl;

    std::cout << "value = " << value << std::endl;
    auto closure4 = [&value]() { value = 100; };
    closure4();
    std::cout << "value = " << value << std::endl;

    std::cout << std::endl << std::endl;
}

// Strange ...
void example_5() {

    std::cout << "example_5" << std::endl;

    std::string str = "Trololo";
    // Capture by reference
    
    //auto lambda = [&str]() { str = "Param-pam-pam"; };

    // What about capture by const reference?
    // Only if you really want...

    // C++14
    // auto lambda2 = [&str = static_cast<const std::string&>(str)]() {
    //     str = "Param-pam-pam";
    // };

    // C++17
    // auto lambda2 = [&str = std::as_const(str)]() {
    //     str = "Param-pam-pam";
    // };

    std::cout << std::endl << std::endl;
}

// []                      // без захвата переменных из внешней области видимости
// [=]                     // все переменные захватываются по значению
// [&]                     // все переменные захватываются по ссылке
// [x, y]                  // захват x и y по значению
// [&x, &y]                // захват x и y по ссылке
// [in, &out]              // захват in по значению, а out — по ссылке
// [=, &out1, &out2]       // захват всех переменных по значению, кроме out1 и out2,	
//                         // 
// [&, x, &y]              // захват всех переменных по ссылке, кроме x…


int main() {

    std::vector<int> values = {0, 1, 2, 3, 3, 3, 4, 5, 6};
    lookupAndPrint(values, 3);

    example_1();
    example_2();
    example_3();
    example_4();

    return 0;
}
