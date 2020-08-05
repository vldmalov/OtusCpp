#include <iostream>
#include <string>


int main () {

    bool condition = true;

    std::cout << "if\n";
    if (int value = 42; condition) {
        std::cout << "true condition: " << value << std::endl;
    }
    else {
        value += 10;
        std::cout << "false condition: " << value << std::endl;
    }
    // value is not visible here

    {
        int value = 42;
        if (condition) {
            std::cout << "true condition: " << value << std::endl;
        }
        else {
            value += 10;
            std::cout << "false condition: " << value << std::endl;
        }
    }

    std::cout << "for:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i;
    }
    // i is not visible here
    std::cout << std::endl;

    std::cout << "switch:\n";
    switch(int other = 37; condition) {
        case true:
            std::cout << "true condition: " << other << std::endl;
            break;
        case false:
            std::cout << "false condition: " << other << std::endl;
    }
    // other is not visible here

    // Not possible for now.....
    // while(std::string line; std::getline(std::cin, line)) {
    //     std::cout << line;
    // }

    return 0;
}
