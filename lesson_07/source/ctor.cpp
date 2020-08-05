#include <iostream>
#include <string>

#ifdef _MSC_VER 
    #define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

// C++11 example

struct SomeStruct {

    explicit SomeStruct(const std::string& value)
        : m_string{value} {
            std::cout << "value ctor" << std::endl;
        }

    // 1 problem
    SomeStruct(const SomeStruct& other) {
         std::cout << "copy ctor" << std::endl;
         m_string = other.m_string;
    }

    // 2 problem
    // SomeStruct(SomeStruct& other) {
    //     std::cout << "non-const copy ctor" << std::endl;
    //     m_string = other.m_string;
    // }

    template<typename TT>
    SomeStruct(TT&& value) 
        : m_string{std::forward<TT>(value)} {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << "universal ctor" << std::endl;
    }

    const std::string& getString() {
        return m_string;
    }

private:
    std::string m_string;
};

int main() {

    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << "0. expect universal ctor here!" << std::endl;
    SomeStruct first{"trololo"};
    std::cout << std::endl;
    
    std::string value = "param";
    std::cout << "1. expect value ctor here!" << std::endl;
    const SomeStruct second{value};
    std::cout << std::endl;

    const std::string cvalue = "trololo";
    std::cout << "2. expect value ctor here!" << std::endl;
    SomeStruct third{cvalue};
    std::cout << std::endl;

    // 2 problem
    // std::cout << "3. expect copy ctor here!" << std::endl;
    // SomeStruct copy{first};
    std::cout << std::endl;

    // 1 problem
    std::cout << "4. expect copy ctor here!" << std::endl;
    SomeStruct copy2{second};
    std::cout << std::endl;

    return 0;
}