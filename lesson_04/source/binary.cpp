#include <iostream>

int main() {
    int value = 1'234'567; // dec
    int value2 = 0xff;     // hex
    int value3 = 0b1111;   // binary
    int value4 = 0137;     // oct

    std::cout << "0b10101010 = " << 0b10101010 << std::endl;

    std::cout << "0b01010101 = " << 0b01010101 << std::endl;

    std::cout << "0b11111111 = " << 0b11111111 << std::endl;

    std::cout << "0b10000000 = " << 0b10000000ul << std::endl;

    return 0;
}