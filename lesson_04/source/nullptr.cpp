#include <iostream>

#define UNUSED(arg) ((void)(arg))

namespace basics {
    void func(int) {
        std::cout << "func(int)" << std::endl;
    }

    void func(char *) {
        std::cout << "func(ptr)" << std::endl;
    }

    void example() {
        // GCC - Compile error
        // error: call of overloaded 'func(NULL)' is ambiguous
        // MSVC - Ok - func(int) will be called
        // func(NULL);

        int i = NULL; // warning
        char *p = NULL;

        // int is = nullptr; // error
        char *ps = nullptr;
        func(nullptr);

        UNUSED(i);
        UNUSED(p);
        UNUSED(ps);
    }
}

namespace middle {
    void func(int* ) {
        std::cout << "func(int* )" << std::endl;
    }

    void func(char *) {
        std::cout << "func(char* )" << std::endl;
    }

    void func(nullptr_t) {
        std::cout << "func(nullptr_t )" << std::endl;
    }

    void example() {
        func(nullptr);
    }
}

int main(int, char *[]) {

    basics::example();

    middle::example();

    return 0;
}