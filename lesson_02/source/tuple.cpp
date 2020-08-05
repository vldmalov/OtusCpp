#include <functional>
#include <iostream>
#include <string>
#include <tuple>

struct foo {
    int id;
    std::string name;
};

auto foo(int, int) {
    return std::make_tuple(std::string("surname"), 19);
}


int main(int, char *[]) {
    auto r = foo(1, 2);

    std::cout << std::get<0>(r) << std::endl;
    std::cout << std::get<1>(r) << std::endl;
    
    std::string sn;
    int old;

    std::make_tuple(std::ref(sn), std::ref(old)) = foo(1, 2);
    std::cout << sn << std::endl;
    std::cout << old << std::endl;

    //auto [sn,old] = foo(1,2);  // for >= C++17

    std::tie(sn, old) = foo(1, 2);


    std::cout << sn << std::endl;
    std::cout << old << std::endl;

    return 0;
}
