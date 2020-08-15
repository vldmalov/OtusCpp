#include <iostream>

template<std::size_t value>
void printValue() {
    std::cout << "size_t " << value << std::endl;
}

template<const char* value>
void printValue() {
    std::cout << "Pointer = " << value << "\t value = " << *value << std::endl;
}



// non-type template parameters
template<auto value>
void printMe() {
    std::cout << value << std::endl;
}

int main() {
    static const char c = 'c';

    printValue<10>();
    printValue<&c>();

    static const int a = 42;

    printMe<10>();
    printMe<'a'>();
    printMe<a>();
    printMe<&a>();

    return 0;
}