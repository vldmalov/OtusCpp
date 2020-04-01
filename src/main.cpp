#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "ipAddresses.h"

int main()
{
//    std::ifstream in("ip_filter.tsv");
//    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to file
    
    try
    {
        std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses(std::cin);

        std::sort(ipAddressPool.begin(), ipAddressPool.end(), std::greater<Utils::ipAddress>());
        std::copy(ipAddressPool.begin(), ipAddressPool.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        
        // TODO filter by first byte and output
        {
            std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{1u, std::nullopt, std::nullopt, std::nullopt});
            std::copy(filtredAddresses.begin(), filtredAddresses.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        }

        // TODO filter by first and second bytes and output
        {
            std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{46u, 70u, std::nullopt, std::nullopt});
            std::copy(filtredAddresses.begin(), filtredAddresses.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        }

        // TODO filter by any byte and output
        {
            std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddressesAny(ipAddressPool, 46u);
            std::copy(filtredAddresses.begin(), filtredAddresses.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
//    std::cin.rdbuf(cinbuf); // Reset to standard input again

    return 0;
}
