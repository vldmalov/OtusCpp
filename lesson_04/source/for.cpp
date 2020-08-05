#include <array>
#include <iostream>
#include <vector>


int main(int, char *[]) {
    int a[10];
    for(const auto& i : a)
    {
        std::cout << i << std::endl;
    }

    std::vector<int> values = {1, 2 , 3, 4, 5, 6};

    int counter = 0;
    for(auto& i : values) {
        i = i + 42;
        values.push_back(42); // bad code. iterators invalidation
        std::cout << i << std::endl;
    }

    std::string s{"hello"};
    for(auto c: s)
    {
        std::cout << c << std::endl;
    }

    return 0;
}



int previous() {
    std::vector<int> values = {0, 1, 2, 3, 4, 5, 6};

    for(auto iter = values.begin(); iter != values.end(); ++iter) {
        if (iter != values.begin()) 
            std::cout << ', ';
        std::cout << *iter;
    }
    std::cout << std::endl;

    for(auto& v : values) {
        std::cout << v << ', '; // TODO , ?
    }
    std::cout << std::endl;


    for(auto iter = values.cbegin(); iter != values.cend(); ++iter) {
        std::cout << *iter << ' ';
    }

    for (const auto& v : values) {
        std::cout << v << ' ';
    }

    for (auto v : values) { // copy here!
        std::cout << v << ' ';
    }


    return 0;
}