#include <iostream>

struct IntWrapper
{
    IntWrapper() : _data{ 0 }
    {
        std::cout << "IntWrapper Default ctor" << std::endl;
    }
    
    explicit IntWrapper(int val) : _data{ val }
    {
        std::cout << "IntWrapper Ctor. Value : " << _data << std::endl;
    }

    IntWrapper(const IntWrapper& other)
    {
        std::cout << "IntWrapper Copy ctor. Value : " << other._data << std::endl;
        _data = other._data;
    }
        
    IntWrapper(const IntWrapper&& other) noexcept
    {
        std::cout << "IntWrapper Move ctor. Value : " << other._data << std::endl;
        _data = other._data;
    }
        
    IntWrapper& operator= (const IntWrapper& other)
    {
        std::cout << "IntWrapper Assign operator. Value : " << other._data << std::endl;
        _data = other._data;
        
        return *this;
    }
        
    IntWrapper& operator= (const IntWrapper&& other) noexcept
    {
        std::cout << "IntWrapper Move assign operator. Value : " << other._data << std::endl;
        _data = other._data;
        
        return *this;
    }
    
    ~IntWrapper()
    {
        std::cout << "IntWrapper Dtor. Value : " << _data << std::endl;
    }
        
    friend bool operator< (const IntWrapper& lhs, const IntWrapper& rhs);
    friend std::ostream& operator<< (std::ostream& os, const IntWrapper& wrapper);
        
private:
    int _data{ 0 };
};

bool operator< (const IntWrapper& lhs, const IntWrapper& rhs)
{
    return lhs._data < rhs._data;
}

std::ostream& operator<< (std::ostream& os, const IntWrapper& wrapper)
{
    os << wrapper._data;
    return os;
}

