#include <string>

auto str_1 = std::string("First string");

thread_local auto str_2 = std::string("Second string");

std::string foo(std::string str_3) {
    static std::string str_4 = "Static string";
    return str_4;
}

int main() {
    auto str_5 = "Local string";

    foo(std::string("argument"));

    auto str_6 = new std::string("new string");
    // ... long code here
    delete str_6;

    return 0;
}