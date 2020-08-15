#include <iostream>

template<typename T>
struct smart_ptr {

    smart_ptr(T* ptr) 
        : m_counter{new std::size_t{1}},
          m_ptr{ptr} {
    }

    smart_ptr(const smart_ptr& other) 
        : m_counter{ other.m_counter },
          m_ptr{ other.m_ptr } {
        ++*m_counter;
    }

    ~smart_ptr() {
        if (--*m_counter == 0) {
            delete(m_ptr);
            delete(m_counter);
        }
    }

private:
    T* m_ptr;
    std::size_t* m_counter;
};

struct SomeStruct {
    SomeStruct() {
        std::cout << "ctor" << std::endl;
    }
    ~SomeStruct() {
        std::cout << "dtor" << std::endl;
    }
};

int main() {
    {
        smart_ptr<SomeStruct> ptr1{new SomeStruct};
        {
            auto ptr2 = ptr1;
        }
    }
    std::cout << "after scope" << std::endl << std::endl;

    return 0;
}