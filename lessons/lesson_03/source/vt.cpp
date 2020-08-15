#include "pretty.h"

#include <iostream>

//   iterate1(1, 2.0, "tri");
template<typename... Args>
void iterate1(Args... values) {
    printf("iterate1: sizeof = %llu values = %d %f %s\n", sizeof...(values), values...);
}

void iterate2() {
    std::cout << std::endl;
}

// iterate2(1, 2.0, "tri");
template<typename T, typename... Args>
void iterate2(T t, Args... args) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << t << std::endl;
    iterate2(args...);
}



template<typename... Args>
void iterate3(Args... args) {
    int a[sizeof...(args)] = {(std::cout << args << std::endl, 0)...};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    // int a[3] = {(std::cout << 1, 0), (std::cout << 2.0, 0), (std::cout << "tri", 0)};

    std::cout << std::endl;
}

int main(int, char *[]) {
    std::cout << "\n\n=====" << std::endl;

    iterate1(1, 2.0, "tri");
    iterate2(1, 2.0, "tri");
    iterate3(1, 2.0, "tri");

    return 0;
}