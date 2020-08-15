#include <iostream>
#include <cassert>
#include <cmath>

double my_sqrt(double value) {
    return std::sqrt(value);
}

int main(int, char *[]) {
    double value = 4.0;

    assert(my_sqrt(value) == 2.0); 
    // assert(my_sqrt(value) == 2.1); // Ooops

    int i = 0;
    // static_assert(i == 0, "failed"); // is not an integral constant

    static_assert(true, "failed");

    const int j = 0;
    static_assert(j == 0, "failed foo");

    return 0;
}


#include <type_traits>
 
template <class T>
void swap(T& a, T& b)
{
    static_assert(std::is_copy_constructible<T>::value,
                  "Swap requires copying");
    static_assert(std::is_nothrow_copy_constructible<T>::value
               && std::is_nothrow_copy_assignable<T>::value,
                  "Swap requires nothrow copy/assign");
    auto c = b;
    b = a;
    a = c;
}


const int MyLibraryVersion = 144;

static_assert(MyLibraryVersion > 100, "Old versions are not supported!");