#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

//#define SOME_DEFINE

#ifdef SOME_DEFINE
bool some_func(int a, int b) {
    return (a >= b)? true : false;
}
#else
bool some_func(int a, int b) {
    return (a > b)? true : false;
}
#endif

/*
    1. preprocessing
    2. tamplate instantiation
    3. compilation
    4. linking
*/

// Example1 - motivation. Compile time error here!
template <typename T>
T get_value1(T t) {
    if (std::is_pointer_v<T>) {
        std::cout << "get_value1 - pointer detected!" << std::endl;
        return *t;
    }
    else {
        std::cout << "get_value1 - value detected!" << std::endl;
        return t;
    }
}

// int main()
// {
//     int value = 42;

//     get_value1(value);
//     get_value1(&value);
// }

// Example2 - old solution - specialization for pointer
template <typename T>
T get_value2(T t) {
    std::cout << "get_value2 - value detected!" << std::endl;
    return t;
}

template <typename T>
T get_value2(T* t) {
    std::cout << "get_value2 - pointer detected!" << std::endl;
    if (t == nullptr)
        throw std::logic_error("nullptr detected!");
    return *t;

}

// int main()
// {
//     int value = 42;

//     get_value2(value);
//     get_value2(&value);
// }

// Example3 - new modern style with constexpr if
template <typename T>
auto get_value3(T t) {
    if constexpr (std::is_pointer_v<T>) {
        std::cout << "get_value3 - pointer detected!" << std::endl;
        return *t;
    }
    else {
        std::cout << "get_value3 - value detected!" << std::endl;
        return t;
    }
    //return std::string("trololo"); // compile error
}

int main()
{
    int value = 42;

    get_value3(value);
    get_value3(&value);

}