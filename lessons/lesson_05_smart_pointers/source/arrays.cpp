#include <iostream>
#include <memory>

struct SomeStruct {
    SomeStruct() {
        std::cout << "ctor" << std::endl;
    }
    ~SomeStruct() {
        std::cout << "dtor" << std::endl;
    }
};

int main() {

    // undefined behavior
    //std::unique_ptr<SomeStruct> wrong{ new SomeStruct[10] };

    // Good. Possible since C++11
    std::unique_ptr<SomeStruct[]> ok{ new SomeStruct[10]};

    // operator[]
    SomeStruct value = ok[5];

    // Compilation error - no operator* for such instance
    // *ok;

    // undefined behavior
    // std::shared_ptr<SomeStruct> wrong2{ new SomeStruct[10] };

    // Impossible in C++11/C++14, but possible in C++17
    std::shared_ptr<SomeStruct[]> ok2{ new SomeStruct[10] };

    // operator[]
    SomeStruct value2 = ok2[5];

    // Compilation error - no operator* for such instance
    // *ok2;

    return 0;
}