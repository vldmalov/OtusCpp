#include "pretty.h"

#include <iostream>
#include <string>

#include <chrono>

struct kg {
    unsigned long long value;

    unsigned long long get() const { return value; }
};

kg operator""_kg(unsigned long long value) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return kg{value};
}

void example1() {
    std::cout << "\nexample1" << std::endl;
    // auto a = 42;
    auto a = 42_kg;
    std::cout << a.get() << std::endl;
}

long double operator""_E(long double value) {
    return value;
}

// Compile error. 
// int operator""_Bool(bool value) {
//     return 0;
// }

void example2() {
    std::cout << "\nexample2" << std::endl;

    // Compile error!
    // std::cout << 42_kg.get() << std::endl;

    // Compile error!
    // auto x = 1.0_E+2.0;
    // Ok
    auto x = 1.0_E + 2.0;

    std::cout << 1E+2 << std::endl;
}

long double operator""_rate(long double value) {
    return value * 2;
}

void example3() {
    std::cout << "\nexample3" << std::endl;

    auto b = 42.0_rate;
    std::cout << b << std::endl;
}

std::string operator""_english(const char *, size_t) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return "sorok dva";
}

unsigned long long operator""_int(unsigned long long value) {
    return value;
}

void example4() {
    std::cout << "\nexample4" << std::endl;

    auto c = "42"_english;
    std::cout << c << std::endl << std::endl;

    {
        using namespace std::string_literals;
        using namespace std::literals;

        auto d = std::string("hello\0world"); // s
        auto e = "hello\0world"s; // s
        std::cout << d << std::endl;
        std::cout << e << std::endl;
        std::cout << typeid(e).name() << std::endl;

    }

    {
        using namespace std::chrono_literals;
        // std::chrono::seconds
        auto seconds = 123s;
        seconds.count();

        // Compile error!
        // 123s.count();
        // Ok
        123s .count();
    }
}


int main(int, char *[]) {

    example1();

    example2();

    example3();

    example4();

    return 0;
}
