#include <array>
#include <iostream>
#include <string>

int main(int argc, char**) {
    std::string value = "First test";

    // What about r-value in lambdas?
    // Not supported in C++11 :(
    // auto wrongLambda = [&&value]() {
    //     // do something
    // };



    // C++14 - capture with an initializer
    auto lambda = [val = std::move(value)]() {
        std::cout << "Hello from lambda function with r-value: " << val << std::endl;
    };
    lambda();
    std::cout << "value now is: " << value << std::endl;



    // C++17
    auto getSize = [] { return 42; };
    
    [[maybe_unused]]
    std::array<int, getSize()> arr; // lambda is explicitly constexpr

    auto stillConstexpr = [](int param) {
        return param;
    };
    [[maybe_unused]] 
    std::array<int, stillConstexpr(42)> arr3;

    auto explicitlyConstexpr = [](int param) constexpr {
        return param;
    };
    [[maybe_unused]] 
    std::array<int, explicitlyConstexpr(42)> arr4;

    [[maybe_unused]] 
    int nonConstexpr = explicitlyConstexpr(argc);

    // Wrong. Non-constexpr call.
    // [[maybe_unused]] std::array<int, explicitlyConstexpr(argc)> arr5;

    return 0;
}