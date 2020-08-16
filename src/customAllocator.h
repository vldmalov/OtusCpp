#pragma once

#include <iostream>
#include "coloredCout.h"

template<typename T, int COUNT>
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
    CustomAllocator(const CustomAllocator<U, COUNT>&)
    {
        std::cout << BOLDYELLOW << __PRETTY_FUNCTION__ << RESET << std::endl;
    }
    
    template<typename U>
    struct rebind {
        using other = CustomAllocator<U, COUNT>;
    };

    pointer allocate(std::size_t n)
    {
        if(_allocatedMem) return _allocatedMem + _constructedCount;
        
        const size_t bytesCount{ COUNT * sizeof(T) };
        void* p = ::operator new(bytesCount);
        if(!p)
        {
            throw std::bad_alloc();
        }
        
        std::cout << BOLDGREEN << __PRETTY_FUNCTION__ << "[n = " << n << "] [addr = " << p << "]"  << RESET << std::endl;
        std::cout << BOLDGREEN << "[bytes allocated = " << bytesCount << "]" << RESET << std::endl;
        
        _allocatedMem = reinterpret_cast<pointer>(p);
        return _allocatedMem;
    }

    void deallocate(pointer p, std::size_t n)
    {
        std::cout << BOLDRED << __PRETTY_FUNCTION__ << "[n = " << n << "] [addr = " << p << "]" << RESET << std::endl;
        std::cout << BOLDRED << "Constructerd count = " << _constructedCount << RESET << std::endl;
        
        if(_allocatedMem && !_constructedCount)
        {
            std::cout << BOLDRED << "DEALLOCATE MEMORY" << RESET << std::endl;
            ::operator delete(_allocatedMem);
        }
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args)
    {
        std::cout << GREEN << __PRETTY_FUNCTION__ << " [addr = " << p << "]" << RESET << std::endl;
        ++_constructedCount;
        new(p) U(std::forward<Args>(args)...);
    }
    
    template<typename U>
    void destroy(U* p)
    {
        std::cout << RED << __PRETTY_FUNCTION__ <<  "[addr = " << p << "]" << RESET << std::endl;
        --_constructedCount;
        p->~U();
    }
    
private:
    pointer _allocatedMem { nullptr };
    size_t _constructedCount{ 0 };
};
