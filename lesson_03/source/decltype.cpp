#include <iostream>

#define UNUSED(variable) (void)variable

float func(float a, float b) {
    throw std::logic_error("Ooooops");
    return a * b / 0;
}

void example_1() {

    decltype(func(1.0f, 2.0f)) dfunc = 175.0f; // dfunc type ?

    int arr[3] = {0, 1, 2};
    decltype(arr[100500]) darr = arr[1]; // darr type?

    UNUSED(dfunc);
    UNUSED(darr);
}

int main() {

    example_1();

    return 0;
}