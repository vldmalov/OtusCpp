#include "versionLib.h"

#include <iostream>

int main()
{
    std::cout << "Application version: " << versionLib::getFullVersion() << std::endl;
    std::cout << "Hello world!" << std::endl;

    return 0;
}
