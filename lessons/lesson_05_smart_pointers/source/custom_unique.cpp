#include <iostream>

template<typename T>
struct smart_ptr {
    smart_ptr(T* ptr) 
        : m_ptr{ptr} {
    }

    ~smart_ptr() {
        delete m_ptr;
    }

    T* get() { 
        return m_ptr; 
    }
private:
    T* m_ptr;
};

struct SomeClass {
    SomeClass() {
        std::cout << "ctor" << std::endl;
    }
    ~SomeClass() {
        std::cout << "dtor" << std::endl;
    }
};

int main() {
    std::cout << "start" << std::endl;
    {
        auto ptr = smart_ptr<SomeClass>{new SomeClass()};
    }
    std::cout << "end" << std::endl;
    return 0;
}