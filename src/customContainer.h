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
        clear();
        _allocator.deallocate(_data, _capacity);
    }
    
    void clear()
    {
        for(size_t idx = 0; idx < _size; ++idx)
        {
            _allocator.destroy(_data + idx);
        }
        _size = 0;
    }
    
    void push_back(const T& value)
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
    
    void pop_back()
    {
        if(empty())
        {
            return;
        }
        _allocator.destroy(end() - 1);
        --_size;
    }
    
    size_t size() const
    {
        return _size;
    }
    
    bool empty() const
    {
        return !_size;
    }
    
    size_t capacity() const
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
    size_t  _size{ 0 };
    size_t  _capacity{ 0 };
    pointer _data;
    
    ALLOC_T _allocator;

};
