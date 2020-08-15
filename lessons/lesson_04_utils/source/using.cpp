#include <iostream>
#include <vector>

typedef int MyInt;

using vi = std::vector<int>;

template<typename T>
using v = std::vector<T>;

int main(int, char *[]) {
    vi a;
    v<int> b;

    return 0;
}