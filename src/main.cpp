#include "customAllocator.h"

#include <iostream>
#include <vector>
#include <map>
#include "intWrapper.h"
#include "coloredCout.h"

static const int ITEMS_COUNT = 10;

int main()
{
    auto simpleMap = std::map<IntWrapper, IntWrapper>{};
    int fact{ 1 };
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        if(idx > 1) fact *= idx;
        simpleMap.emplace(idx, fact);
    }
        
    auto customAllocMap = std::map<IntWrapper, IntWrapper, std::less<IntWrapper>,
        CustomAllocator<std::pair<const IntWrapper, IntWrapper>, 10>>{};
    
    fact = 1;
    for(int idx = 0; idx < ITEMS_COUNT; ++idx)
    {
        if(idx > 1) fact *= idx;
        
        std::cout << BOLDBLUE << "\n===== myMap size : " << customAllocMap.size() << RESET << std::endl;
        customAllocMap.emplace(idx, fact);
    }
    
    std::cout << BOLDBLUE << "===== After map has been filled out" << RESET << std::endl;
        
    for(const auto& [key, val] : customAllocMap)
    {
        std::cout << key << " " << val << std::endl;
    }
   
    std::cout << BOLDBLUE << "===== Before programm end" << RESET << std::endl;

    return 0;
}
