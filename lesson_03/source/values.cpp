#include <iostream>
#include <string>
#include <vector>
#include <utility>

using vec = std::vector<int>;

int& vecElem(vec& v, int elem) {
    return v[elem];
}

int vecValue(vec& v, int elem) {
    return v[elem];
}

// int&& vecMovable(vec &v, int elem) {
//    return v[elem];
// }

void printVec(const vec& v) {
    auto lastElemIt = v.begin() + (v.size() - 1);
    auto current = v.begin();
    auto end = v.end();

    for (; current != end; ++current) {
        std::cout << *current;
        if (current != lastElemIt) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int a = 42;
    int b = a;

    vec v = vec{1, 2, 3, 4, 5};
    printVec(v);
    vecElem(v, 3) = 99;
    printVec(v);
    v[3] = 100;
    printVec(v);

    // 42 = a;
    // vecValue(v, 3) = 99;
    // int c = vecMovable(v, 3);

    int &ref1 = a;
    const int &ref2 = b;
    // int& ref3 = 42;
    const int &ref4 = 42;

    int &&ref5 = 42;
    // int &&ref6 = a;
    const int &&ref7 = 42; // ???
}








