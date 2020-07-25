#include "versionLib.h"
#include "ipAddresses.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    //std::cout << "Application version: " << versionLib::getFullVersion() << std::endl;
    //std::cout << "Hello world!" << std::endl;
    
//    std::ifstream in("ip_filter.tsv");
//    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to file
    
    try
    {
        std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses();

        // 222.173.235.246
        // 222.130.177.64
        // ...
        // 1.29.168.152
        // 1.1.234.8
        std::sort(ipAddressPool.begin(), ipAddressPool.end(), std::greater<Utils::ipAddress>());
        std::copy(ipAddressPool.begin(), ipAddressPool.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        
        // TODO filter by first byte and output
        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8
        {
            std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{1u, std::nullopt, std::nullopt, std::nullopt});
            std::copy(filtredAddresses.begin(), filtredAddresses.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        }

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        {
            std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{46u, 70u, std::nullopt, std::nullopt});
            std::copy(filtredAddresses.begin(), filtredAddresses.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        }

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
        {
            std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddressesAny(ipAddressPool, 46u);
            std::copy(filtredAddresses.begin(), filtredAddresses.end(), std::ostream_iterator<Utils::ipAddress>(std::cout, "\n"));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //std::cin.rdbuf(cinbuf); // Reset to standard input again

    return 0;
}
