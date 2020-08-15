#include <iostream>
#include <string>

void example1() {
    std::cout << "\nexample1" << std::endl;

    std::string name{"Vasia"};

    std::move(name);

    std::cout << name << std::endl;
}

void example2() {
    std::cout << "\nexample2" << std::endl;

    std::string name{"Vasia"};

    std::string str = std::move(name);

    std::cout << name << std::endl;
}

int main(int, char *[]) {

    example1();

    example2();

    return 0;
}