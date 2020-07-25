#pragma once

#include <string>
#include <array>
#include <vector>
#include <optional>

namespace Utils
{
    using uchar = unsigned char;
    
    class ipAddress
    {
    public:
        explicit ipAddress(const std::string& str);
        
        uchar& GetPart(size_t idx);
        const uchar& GetPart(size_t idx) const;
        
        static constexpr size_t GetPartsCount();
        
    public:
        static constexpr size_t IP_ADDRESS_PARTS_COUNT{ 4 };
        
    private:
        std::array<uchar, IP_ADDRESS_PARTS_COUNT> _data;
    };

    using ipAddressMask = std::array<std::optional<uchar>, ipAddress::IP_ADDRESS_PARTS_COUNT>;

    std::ostream& operator<<(std::ostream& os, const ipAddress& address);
    bool operator<(const ipAddress& lhs, const ipAddress& rhs);
    bool operator>(const ipAddress& lhs, const ipAddress& rhs);

    std::vector<ipAddress> ReadIpAdresses();
    std::vector<ipAddress> FilterIpAddresses(const std::vector<ipAddress>& ipAddresses, const ipAddressMask& mask);
    std::vector<ipAddress> FilterIpAddressesAny(const std::vector<ipAddress>& ipAddresses, uchar filterVal);
}
