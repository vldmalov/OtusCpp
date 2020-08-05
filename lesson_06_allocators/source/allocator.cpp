#ifndef __PRETTY_FUNCTION__
#include "pretty.h"
#endif

#include <iostream>
#include <vector>
#include <map>

#define USE_PRETTY 1

template<typename T>
struct logging_allocator {
    using value_type = T;

    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template<typename U>
    struct rebind {
        using other = logging_allocator<U>;
    };

    logging_allocator() = default;
    ~logging_allocator() = default;

    
    template<typename U>
    logging_allocator(const logging_allocator<U>&) {

    }

    T *allocate(std::size_t n) {
#ifndef USE_PRETTY
        std::cout << "allocate: [n = " << n << "]" << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
#endif
        auto p = std::malloc(n * sizeof(T));
        if (!p)
            throw std::bad_alloc();
        return reinterpret_cast<T *>(p);
    }

    void deallocate(T *p, std::size_t n) {
#ifndef USE_PRETTY
        std::cout << "deallocate: [n  = " << n << "] " << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
#endif
        std::free(p);
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args) {
#ifndef USE_PRETTY
        std::cout << "construct" << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        new(p) U(std::forward<Args>(args)...);
    };
    
    
    //template<typename U> //???
    void destroy(T *p) {
#ifndef USE_PRETTY
        std::cout << "destroy" << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        p->~T();
    }
};

int main(int, char *[]) {
    auto ptr2 = std::make_shared<int>(43);
    
    {
        auto v = std::vector<int, logging_allocator<int>>{};
        //v.reserve(5);

        for (int i = 0; i < 6; ++i) {
            std::cout << "vector size = " << v.size() << std::endl;
            v.emplace_back(i);
            std::cout << std::endl;
        }
    }
    
    std::cout<< "##### End of output for vector #####"<<std::endl;
//     for (auto i: v) {
//         std::cout << i << std::endl;
//     }
     {
         auto m = std::map<int, int, std::less<int>,
             logging_allocator<std::pair<const int, int>>>{};
         for (int i = 0; i < 1; ++i) {
             m[i] = i;
             std::cout << std::endl;
         }
     }

    std::cout<< "##### End of output for map #####"<<std::endl;

    return 0;
}
