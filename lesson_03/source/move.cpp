#include <iostream>
#include <string>
#include <utility>

void someStrangeFunction() {
    std::string name{"Pish pish ololo"};

    std::move(name);

    std::cout << name << std::endl;
}


template <typename T>
typename std::remove_reference<T>::type&& move(T&& arg) {
    return static_cast<typename std::remove_reference<T>::type&&>(arg);
}


void foo(const std::string& val) {
    std::cout << "const std::string&" << std::endl;
}

void foo(std::string& val) {
    std::cout << "std::string&" << std::endl;
}

void foo(std::string&& bigString) {
    std::cout << "std::string&&" << std::endl;
}


int main(int argc, char* arg[]) {
    someStrangeFunction();

    std::string str = "Ya voditel nlo";
    foo("Ya voditel nlo");
    foo(str);
    foo(std::move(str));

    return 0;
}