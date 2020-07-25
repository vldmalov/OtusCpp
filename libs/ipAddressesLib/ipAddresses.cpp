#include "ipAddresses.h"

#include <sstream>
#include <vector>
#include <iostream>
#include <cassert>
#include <optional>

namespace Utils
{
    // ("",  '.') -> [""]
    // ("11", '.') -> ["11"]
    // ("..", '.') -> ["", "", ""]
    // ("11.", '.') -> ["11", ""]
    // (".11", '.') -> ["", "11"]
    // ("11.22", '.') -> ["11", "22"]
    std::vector<std::string> split(const std::string &str, char delim)
    {
        std::vector<std::string> result;

        std::string::size_type leftIdx{ 0 };
        std::string::size_type rightIdx{ str.find_first_of(delim) };
        while(rightIdx != std::string::npos)
        {
            result.push_back(str.substr(leftIdx, rightIdx - leftIdx));

            leftIdx = rightIdx + 1;
            rightIdx = str.find_first_of(delim, leftIdx);
        }

        result.push_back(str.substr(leftIdx));

        return result;
    }

	ipAddress::ipAddress(const std::string& input)
    {
        std::vector<std::string> ipAddressParts = split(input, '.');
        assert(ipAddressParts.size() == IP_ADDRESS_PARTS_COUNT);
        
        if(ipAddressParts.size() == IP_ADDRESS_PARTS_COUNT)
        {
            for(size_t idx = 0; idx < ipAddressParts.size(); ++idx)
            {
                _data[idx] = std::stoi(ipAddressParts[idx]);
            }
        }
    }

    uchar& ipAddress::GetPart(size_t idx)
    {
        assert(idx < IP_ADDRESS_PARTS_COUNT);
        return _data[idx];
    }

    const uchar& ipAddress::GetPart(size_t idx) const
    {
        assert(idx < IP_ADDRESS_PARTS_COUNT);
        return _data[idx];
    }

    size_t constexpr ipAddress::GetPartsCount()
    {
        return IP_ADDRESS_PARTS_COUNT;
    }

    std::ostream& operator<<(std::ostream& os, const ipAddress& address)
    {
        os << (int)address.GetPart(0) << '.' << (int)address.GetPart(1) << '.'
           << (int)address.GetPart(2) << '.' << (int)address.GetPart(3);
        return os;
    }

    bool operator<(const ipAddress& lhs, const ipAddress& rhs)
    {
        for(size_t idx = 0; idx < ipAddress::GetPartsCount(); ++idx)
        {
            if(lhs.GetPart(idx) != rhs.GetPart(idx))
            {
                return lhs.GetPart(idx) < rhs.GetPart(idx);
            }
        }
        return false;
    }

    bool operator>(const ipAddress& lhs, const ipAddress& rhs)
    {
        return rhs < lhs;
    }
    
    std::vector<ipAddress> ReadIpAdresses()
    {
        std::vector<ipAddress> ipAddressPool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> lineParts = split(line, '\t');
            ipAddressPool.emplace_back(lineParts.at(0));
        }
        
        return ipAddressPool; // NRVO
    }

    std::vector<ipAddress> FilterIpAddresses(const std::vector<ipAddress>& ipAddresses, const ipAddressMask& mask)
    {
        std::vector<ipAddress> result;
        
        std::copy_if(ipAddresses.begin(), ipAddresses.end(), std::back_inserter(result),
             [&mask](const ipAddress& ip)
            {
                for(size_t partIdx = 0; partIdx < mask.size(); ++partIdx)
                {
                    if(mask[partIdx] && mask[partIdx].value() != ip.GetPart(partIdx))
                    {
                        return false;
                    }
                }
                return true;
            });
        
        return result; // NRVO
    }

    std::vector<ipAddress> FilterIpAddressesAny(const std::vector<ipAddress>& ipAddresses, uchar filterVal)
    {
        std::vector<ipAddress> result;
        
        std::copy_if(ipAddresses.begin(), ipAddresses.end(), std::back_inserter(result),
             [filterVal](const ipAddress& ip)
            {
                for(size_t partIdx = 0; partIdx < ipAddress::IP_ADDRESS_PARTS_COUNT; ++partIdx)
                {
                    if(ip.GetPart(partIdx) == filterVal)
                    {
                        return true;
                    }
                }
                return false;
            });
        
        return result; // NRVO
    }
}
