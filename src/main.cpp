#include "customAllocator.h"

#include <iostream>
#include <vector>
#include <map>
#include "coloredCout.h"

struct IntWrapper
{
    IntWrapper() : _data{ 0 }
    {
        std::cout << "Default ctor" << std::endl;
    }
    
    explicit IntWrapper(int val) : _data{ val }
    {
        std::cout << "Ctor. Value : " << _data << std::endl;
    }

    IntWrapper(const IntWrapper& other)
    {
        std::cout << "Copy ctor. Value : " << other._data << std::endl;
        _data = other._data;
    }
        
    IntWrapper(const IntWrapper&& other) noexcept
    {
        std::cout << "Move ctor. Value : " << other._data << std::endl;
        _data = other._data;
    }
        
    IntWrapper& operator= (const IntWrapper& other)
    {
        std::cout << "Assign operator. Value : " << other._data << std::endl;
        _data = other._data;
        
        return *this;
    }
        
    IntWrapper& operator= (const IntWrapper&& other) noexcept
    {
        std::cout << "Move assign operator. Value : " << other._data << std::endl;
        _data = other._data;
        
        return *this;
    }
    
    ~IntWrapper()
    {
        std::cout << "Dtor. Value : " << _data << std::endl;
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

static const int ITEMS_COUNT = 10;

int main()
{
    auto myMap = std::map<IntWrapper, IntWrapper, std::less<IntWrapper>,
        CustomAllocator<std::pair<const IntWrapper, IntWrapper>>>{};
    
    int fact{ 1 };
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        if(idx > 1) fact *= idx;
        
        std::cout << BOLDBLUE << "\n===== myMap size : " << myMap.size() << RESET << std::endl;
        myMap.emplace(idx, fact);
        //myMap.insert_or_assign(IntWrapper{idx}, IntWrapper{fact});
        //myMap[IntWrapper{idx}] = IntWrapper(fact);
    }
    
    std::cout << BOLDBLUE << "===== After map has been filled out" << RESET << std::endl;
        
    for(const auto& [key, val] : myMap)
    {
        std::cout << key << " " << val << std::endl;
    }
   
    std::cout << BOLDBLUE << "===== Before programm end" << RESET << std::endl;

    return 0;
}
