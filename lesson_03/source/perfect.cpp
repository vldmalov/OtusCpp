#include "pretty.h"

#include <iostream>
#include <string>
#include <utility>
#include <stdio.h>

void foo(const int& i, const std::string& s) {
    std::cout << "i = " << i << std::endl;
    std::cout << "s = " << s << std::endl;
    std::cout << "=========" << std::endl;
}

template <typename T1, typename T2>
void wrapDummy(T1 t1, T2 t2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    foo(t1, t2);
}

template <typename T1, typename T2>
void wrap(T1& t1, T2& t2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    foo(t1, t2);
}

template <typename T1, typename T2>
void wrap(const T1& t1, const T2& t2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    foo(t1, t2);
}

void goo(int &i, const std::string& s) {
    i = 42;
    std::cout << "s = " << s << std::endl;
}

template<class T>
T&& forward(typename std::remove_reference<T>::type& t) noexcept {
  return static_cast<T&&>(t);
}

template <class T>
T&& forward(typename std::remove_reference<T>::type&& t) noexcept {
  return static_cast<T&&>(t);
}

template <typename T> 
void simpleTemplate(T v){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    const T& val = v;
    std::cout << "val = " << val << std::endl;;
}

template <typename... Args>
void printWrapper(const std::string &format, Args&&... args)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    printf(format.c_str(), std::forward<Args>(args)...);
}

int main() {
    int i = 42;
    std::string s = "Vasya";
    foo(i, s);
    wrap(i, s);

    foo(42, "Vasya");
    wrap(42, "Vasya");

    simpleTemplate<int&>(i);
    simpleTemplate<int&&>(std::move(i));

    printWrapper("%d and %s\n", i, s.c_str());
    return 0;
}