#include <iostream>
#include <vector>
#include <map>

#include "intWrapper.h"
#include "coloredCout.h"
#include "customAllocator.h"
#include "customContainer.h"

static const int ITEMS_COUNT = 10;

void SimpleMapTest();
void CustomAllocMapTest();
void CustomContainerTest();
void CustomContainerWithCustomAllocTest();

int main()
{
    SimpleMapTest();
    CustomAllocMapTest();
    CustomContainerTest();
    CustomContainerWithCustomAllocTest();

    std::cout << BOLDBLUE << "===== Before programm end" << RESET_COLOR << std::endl;
    return 0;
}

void SimpleMapTest()
{
    std::cout << BOLDBLUE << "===== SimpleMapTest =====" << RESET_COLOR << std::endl;
    
    auto simpleMap = std::map<IntWrapper, IntWrapper>{};
    int fact{ 1 };
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        if(idx > 1) fact *= idx;
        simpleMap.emplace(idx, fact);
    }
}

void CustomAllocMapTest()
{
    std::cout << BOLDBLUE << "===== CustomAllocMapTest =====" << RESET_COLOR << std::endl;
    
    auto customAllocMap = std::map<IntWrapper, IntWrapper, std::less<IntWrapper>,
        CustomAllocator<std::pair<const IntWrapper, IntWrapper>>>{};
    
    int fact{ 1 };
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        if(idx > 1) fact *= idx;
        
        std::cout << BLUE << "\nMap size : " << customAllocMap.size() << RESET_COLOR << std::endl;
        customAllocMap.emplace(idx, fact);
    }
    
    std::cout << BLUE << "After map has been filled out" << RESET_COLOR << std::endl;
        
    for(const auto& [key, val] : customAllocMap)
    {
        std::cout << BLUE << key << " " << val << RESET_COLOR << std::endl;
    }
}

void CustomContainerTest()
{
    std::cout << BOLDBLUE << "===== CustomContainerTest =====" << RESET_COLOR << std::endl;
    
    auto myContainer = CustomContainer<IntWrapper, std::allocator<IntWrapper>>{};
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        myContainer.pushBack(IntWrapper(idx));
        std::cout << BLUE << "Size: " << myContainer.getSize() << " Capacity: " << myContainer.getCapacity() << RESET_COLOR << std::endl;
    }
    
    std::cout << BLUE << "myContainer has been filled out" << RESET_COLOR << std::endl;
    for(auto& item : myContainer)
    {
        std::cout << BLUE << item << " " << RESET_COLOR;
    }
    std::cout << std::endl;
}

void CustomContainerWithCustomAllocTest()
{
    std::cout << BOLDBLUE << "===== CustomContainerWithCustomAllocTest =====" << RESET_COLOR << std::endl;

    auto myContainer = CustomContainer<IntWrapper, CustomAllocator<IntWrapper>>{};
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        myContainer.pushBack(IntWrapper(idx));
        std::cout << BLUE << "Size: " << myContainer.getSize() << " Capacity: " << myContainer.getCapacity() << RESET_COLOR << std::endl;
    }

    std::cout << "myContainer has been filled out" << RESET_COLOR << std::endl;
    for(auto& item : myContainer)
    {
        std::cout << BLUE << item << " " << RESET_COLOR;
    }
    std::cout << std::endl;
}
