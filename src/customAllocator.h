#pragma once

#include <iostream>
#include "coloredCout.h"

template<typename T>
struct CustomAllocator : public std::allocator<T>
{
    using value_type = T;
    
    using pointer = T*;
    using const_pointer = const T*;
    
    using reference = T&;
    using const_reference = const T&;

    CustomAllocator() = default;
    ~CustomAllocator() = default;
    
    template<typename U>
    CustomAllocator(const CustomAllocator<U>&)
    {
        std::cout << BOLDYELLOW << __PRETTY_FUNCTION__ << RESET << std::endl;
    }
    
    template<typename U>
    struct rebind {
        using other = CustomAllocator<U>;
    };

    pointer allocate(std::size_t n)
    {
        const size_t bytesCount{ n * sizeof(T) };
        void* p = ::operator new(bytesCount);
        if(!p)
        {
            throw std::bad_alloc();
        }
        
        std::cout << BOLDGREEN << __PRETTY_FUNCTION__ << "[n = " << n << "] [addr = " << p << "]"  << RESET << std::endl;
        std::cout << BOLDGREEN << "[bytes allocated = " << bytesCount << "]" << RESET << std::endl;
        
        return reinterpret_cast<pointer>(p);
    }

    void deallocate(pointer p, std::size_t n)
    {
        std::cout << BOLDRED << __PRETTY_FUNCTION__ << "[n = " << n << "] [addr = " << p << "]" << RESET << std::endl;
        ::operator delete(p);
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args)
    {
        std::cout << GREEN << __PRETTY_FUNCTION__ << " [addr = " << p << "]" << RESET << std::endl;
        new(p) U(std::forward<Args>(args)...);
    };
    
    template<typename U>
    void destroy(U* p)
    {
        std::cout << RED << __PRETTY_FUNCTION__ <<  "[addr = " << p << "]" << RESET << std::endl;
        p->~U();
    }
    
private:
    pointer _allocatedMem { nullptr };
    size_t _constructedCount{ 0 };
};
