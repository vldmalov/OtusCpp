#include <iostream>


namespace motivation {
    enum Alphabet {
        a, b, c
    };

    void func(Alphabet ) {
    }

    void func2(int ) {
    }

    void example() {
        Alphabet value = Alphabet::a; // it works
        Alphabet value2 = a; // it works also

        func(value); // it works
        func2(value); // it works also
    }
}

namespace basics {

    enum class Digit : uint64_t {
        one = 1, 
        two = 193, 
        three = 247
    };

    void func(Digit ) {

    }

    void func2(int ) {

    }

    void example() {
        // Digit value = one; // Compile error
        Digit value = Digit::one;

        func(value); // it works
        // func2(value); // Compile error
        func2(static_cast<int>(value)); // it works
    }
}

namespace advanced {

    namespace {
        enum Alphabet {
            a, b, c
        };
    }

    void func(Alphabet ) {
    }

    void func2(int ) {
    }

    void example() {
        Alphabet value = Alphabet::a; // it works
        Alphabet value2 = a; // it works also

        func(value); // it works
        func2(value); // it works also
    }

}

int main(int, char *[]) {

    motivation::example();

    basics::example();

    advanced::example();

    return 0;
}