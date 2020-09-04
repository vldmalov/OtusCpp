#pragma once

#include <iostream>
#include "coloredCout.h"


template<typename T, typename ALLOC_T = std::allocator<T>>
struct CustomContainer final
{
    using value_type = T;
    
    using pointer = T*;
    using const_pointer = const T*;
    
    using reference = T&;
    using const_reference = const T&;

public:
    CustomContainer()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    ~CustomContainer()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        for(size_t idx = 0; idx < _size; ++idx)
        {
            _allocator.destroy(_data + idx);
        }
        _allocator.deallocate(_data, _capacity);
    }
    
    void pushBack(const T& value)
    {
        if(_size == _capacity)
        {
            _capacity = !_capacity ? 1 : 2 * _capacity;
            pointer newData = _allocator.allocate(_capacity);
            
            if(_size)
            {
                std::copy(begin(), end(), newData);
                _allocator.deallocate(_data, _size);
            }
            std::swap(_data, newData);
        }
        
        _allocator.construct(end(), value);
        ++_size;
    }
    
    size_t getSize() const
    {
        return _size;
    }
    
    size_t getCapacity() const
    {
        return _capacity;
    }
    
    pointer begin() const
    {
        return _data;
    }
    
    pointer end() const
    {
        return _data + _size;
    }

private:
    ALLOC_T _allocator;
    size_t  _size{ 0 };
    size_t  _capacity{ 0 };
    pointer _data;
};
