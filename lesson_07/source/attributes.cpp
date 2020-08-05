#include <iostream>

// Since C++11
[[noreturn]] void func() {
    std::abort();
}

void testNoreturn() {
    int someValue = 42;
    func();
    std::cout << someValue << std::endl;
}

// Since C++11
void print2(int * [[carries_dependency]] val)
{
    std::cout<< *val <<std::endl;
}

// Since C++14
[[deprecated]] int very_old_func() {
    return 76;
}

// Since C++17
int switchFunc(int value) {
    int result = 0;
    switch(value) {
        case 0:
            result = 10;
            [[fallthrough]];
        case 1:
            result += 15;
            break;
        case 3:
            result = 72;
            [[fallthrough]];
        case 4:
            result += 15;
            break;
        default:
            result = 777;
    }
    return result;
}

// Since C++17
[[nodiscard]]
int funcNoDiscard() {
    return 743;
}

int main() {

    [[maybe_unused]]
    int someValue = 0;

    func();
    std::cout << very_old_func() << std::endl;

    switchFunc(123);

    // Warning here
    funcNoDiscard();

    return 0;
}