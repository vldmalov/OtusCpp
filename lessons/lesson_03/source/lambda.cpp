#include "pretty.h"

#include <algorithm>
#include <iostream>
#include <vector>

#define UNUSED(variable) (void)variable

struct Closure {
    explicit Closure(int z) : m_z(z) {};
    
    template<typename T, typename R>
    int operator()(T a, R b) const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return  m_z + a + b;
    }
private:
    int m_z;
};

void example1() {
    std::cout << "\nexample1:" << std::endl;

    int value = 1;
    Closure closure{value};
    std::cout << closure(2, 3) << std::endl;
}

void example2() {
    std::cout << "\nexample2:" << std::endl;

    int value = 1;
    auto lambda = [value](auto a, auto b) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return  value + a + b;
    };
    std::cout << lambda(2, 3) << std::endl;
    std::cout << lambda(2.0f, 3) << std::endl;
}

int main() {

    example1();
    example2();

    return 0;
}
