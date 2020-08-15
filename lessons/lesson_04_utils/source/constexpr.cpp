#include <array>
#include <iostream>

#define UNUSED(arg) ((void)(arg))

// Example1 - just a literals
void example1() {
    int carray[2] = {0};
    static_assert(2 < 3, "something wrong....");
    std::array<int, 2> array;

    UNUSED(carray);
    UNUSED(array);
}

// Example1.2 - why it works with GCC and clang?? 
// void example1_2() {
//     int size = 2;
//     int carray[size]; // Warning! It is not what you want!
    
//     carray[0] = 42;
// }

// Example2 - variables
// void example2() {
//     int size = 2;
//     int carray[size]; // Warning! It is not what you want!
//     static_assert(size < 3, "something wrong....");
//     std::array<int, size> array;

//     UNUSED(carray);
//     UNUSED(array);
// }

// Example3 - const variables
void example3() {
    const int size = 2;
    int carray[size] = {0}; // Good now.
    static_assert(size < 3, "something wrong.....");
    std::array<int, size> array;

    UNUSED(carray);
    UNUSED(array);
}


// Example4 - function
// const int justAFunction(const int value) {
//     return value * 2;
// }

// void example4() {
//     const int size = justAFunction(2);
//     int carray[size] = {0}; // Warning! It is not what you want!
//     static_assert(size < 30, "something wrong.....");
//     std::array<int, size> array;

//     UNUSED(carray);
//     UNUSED(array);
// }

// Example5 - constexpr function
constexpr int constexprFunction(int value) { 
    return value * 2;
}

void example5() {
    const int size = constexprFunction(2);
    int carray[size] = {0}; // Good now.
    static_assert(size < 30, "something wrong.....");
    std::array<int, size> array;

    UNUSED(carray);
    UNUSED(array);
}

// Example6 - constexpr function
constexpr int constexprFunction2(int value) { 
    return value * 2;
}

void example6() {
    // Bad
    // {
    //     int initial = 2;
    //     const int size = constexprFunction2(initial);
    //     int carray[size] = {0};
    //     static_assert(size < 30, "something wrong.....");
    //     std::array<int, size> array;
    //
    //     UNUSED(array);
    // }

    // Good
    {
        const int initial = 2;
        const int size = constexprFunction2(initial);
        int carray[size] = {0};
        static_assert(size < 30, "something wrong.....");
        std::array<int, size> array;

        UNUSED(array);
    }

}



// Advanced

struct Kg {
    constexpr Kg(int value) : m_value(value) {
           
    }
    
    constexpr int get() const {
        return m_value;
    }
private:
    int m_value;
};

int advanced() {
    constexpr const Kg kg{42};
    static_assert(kg.get() > 10, "something wrong");

    constexpr int a = 42;
    int b = a;
    // constexpr int c = b; // compile error
    
   return 0;
}


int main(int, char*[]) {

    example1();
    // example2();
    example3();
    // example4();
    example5();
    example6();

    advanced();

    return 0;
}