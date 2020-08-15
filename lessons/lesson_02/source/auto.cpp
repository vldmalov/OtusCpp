#include "header.h"
#include "pretty.h"

#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

#define UNUSED(variable) (void)variable

// By the way...
namespace test {
    typedef std::vector<std::map<std::string, std::size_t>> Dictionaries;
    using Dictionaries = std::vector<std::map<std::string, std::size_t>>;
}

// Basic
void example_1() {

    int i = 10; // of course 10 is int.
    auto ai = 10; // 10 is int -> ai is int
    auto ai2 = i; // i is int -> ai2 is int

    UNUSED(i);
    UNUSED(ai);
    UNUSED(ai2);
}


void motivation() {
    std::vector<std::list<std::map<int, std::string>>> someStrangeVector;

    // Just an iterator
    std::vector<std::list<std::map<int, std::string>>>::const_iterator citer = someStrangeVector.cbegin();

    // for cycle
    for (std::vector<std::list<std::map<int, std::string>>>::const_iterator ci = someStrangeVector.cbegin();
        ci != someStrangeVector.cend();
        ++ci) {
        // do something
    }

    // of cource, we may use using from C++11 (or typedef for legacy)
    using CIter = std::vector<std::list<std::map<int, std::string>>>::const_iterator;

    CIter citer2 = someStrangeVector.cbegin();

    // auto is much more pretty
    auto citer3 = someStrangeVector.cbegin();

    for(auto ci = someStrangeVector.cbegin(); ci != someStrangeVector.cend(); ++ci) {
        // do something
    }

    UNUSED(citer);
    UNUSED(citer2);
    UNUSED(citer3);
}


int sum(int a, int b) {
    return a + b;
}


// Easy
void example_2() {

    auto s = sum(1, 2); // s type ?

    float f = 1 + 2;
    auto af = 1 + 2; // af type ?

    std::string str = "hello";
    auto astr = "hello"; // astr type ?

    auto s2 = sum(1.0, 2.0); // s2 type ?

    UNUSED(s);
    UNUSED(f);
    UNUSED(af);
    UNUSED(str);
    UNUSED(astr);
    UNUSED(s2);
}


// Middle
int someFunction(int a, int b) {
    return a + b;
}

auto someFunction2(int a, int b) { // return type ?
    return a + b;
}

auto someFunction3(int a, float b) { // return type ?
    return a + b;
}

// auto someFunction4(int a, float b) { // return type ?
//     if (a)
//         return a;
//     else
//         return b;
// }

template<typename T>
void tfunc(T ) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// Hard
void example_3() {

    std::cout << "example_3" << std::endl;

    const int ci = 42;
    auto aci = ci; // aci type ?
    tfunc(ci);

    //aci.trololo;

    const int& crefi = ci;
    auto acrefi = crefi; // crefi type ?
    tfunc(crefi);

    volatile float vf = 54;
    auto avf = vf; // avi type ?
    tfunc(vf);

    int i = 137;

    int * ptr = &i;
    auto aptr = ptr; // aptr type ?

    const int * cptr = &i;
    auto acptr = cptr; // acptr type ?
    

    const int * const cptrc = &i;
    auto acptrc = cptrc; // acptrc type ?

    UNUSED(aci);
    UNUSED(acrefi);
    UNUSED(avf);
    UNUSED(aptr);
    UNUSED(acptr);
    UNUSED(acptrc);
}



// Strange
template<typename T>
void tfunc2(T param) {
    UNUSED(param);
}

void example_4() {

    auto il = {1, 2, 3, 4, 5, 6, 7};
    tfunc2(il);

    //tfunc2({1, 2, 3, 4, 5, 6, 7});
    tfunc2(std::initializer_list<int>{1, 2, 3, 4, 5, 6, 7});
}


int main(int, char *[]) {

    example_1();
    example_2();
    example_3();
    example_4();

    // Compile time error
    // auto result = headerFunc(42, 45);

    return 0;
}
