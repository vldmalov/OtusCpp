#include "gtest/gtest.h"

#include "versionLib.h"
#include "ipAddresses.h"

#include "fstream"

const std::string IP_TEST_DATA = "255.255.255.255    111    0\n1.0.0.0    5    6\n1.2.3.4    2    1\n179.210.145.4    22    0\n219.4.120.135    486    0";

TEST(test_version, test_valid_version)
{
	EXPECT_EQ(versionLib::getMajorVersion(), 0ul);
	EXPECT_EQ(versionLib::getMinorVersion(), 0ul);
	ASSERT_GT(versionLib::getPatchVersion(), 0ul);
}

TEST(test_ip_filter, read_ip_adresses)
{
    // Arrange
    std::stringstream ssTestData(IP_TEST_DATA);

    // Act
    std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses(ssTestData);

    // Assert
    EXPECT_EQ(ipAddressPool.size(), 5ul);
    ASSERT_TRUE(ipAddressPool.at(0) == Utils::ipAddress("255.255.255.255"));
    ASSERT_TRUE(ipAddressPool.at(1) == Utils::ipAddress("1.0.0.0"));
    ASSERT_TRUE(ipAddressPool.at(2) == Utils::ipAddress("1.2.3.4"));
    ASSERT_TRUE(ipAddressPool.at(3) == Utils::ipAddress("179.210.145.4"));
    ASSERT_TRUE(ipAddressPool.at(4) == Utils::ipAddress("219.4.120.135"));
}

TEST(test_ip_filter, filter_ip_adresses)
{
    // Arrange
    std::stringstream ssTestData(IP_TEST_DATA);
    std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses(ssTestData);

    // Act
    std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{1u, std::nullopt, std::nullopt, std::nullopt});

    // Assert
    EXPECT_EQ(filtredAddresses.size(), 2ul);
    ASSERT_TRUE(filtredAddresses.at(0) == Utils::ipAddress("1.0.0.0"));
    ASSERT_TRUE(filtredAddresses.at(1) == Utils::ipAddress("1.2.3.4"));
}

TEST(test_ip_filter, filter_ip_adresses_exact)
{
    // Arrange
    std::stringstream ssTestData(IP_TEST_DATA);
    std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses(ssTestData);

    // Act
    std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{179u, 210u, 145u, 4u});

    // Assert
    EXPECT_EQ(filtredAddresses.size(), 1ul);
    ASSERT_TRUE(filtredAddresses.at(0) == Utils::ipAddress("179.210.145.4"));
}

TEST(test_ip_filter, filter_ip_adresses_none)
{
    // Arrange
    std::stringstream ssTestData(IP_TEST_DATA);
    std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses(ssTestData);

    // Act
    std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddresses(ipAddressPool, Utils::ipAddressMask{2u, std::nullopt, std::nullopt, std::nullopt});

    // Assert
    ASSERT_TRUE(filtredAddresses.empty());
}

TEST(test_ip_filter, filter_ip_adresses_any)
{
    // Arrange
    std::stringstream ssTestData(IP_TEST_DATA);
    std::vector<Utils::ipAddress> ipAddressPool = Utils::ReadIpAdresses(ssTestData);

    // Act
    std::vector<Utils::ipAddress> filtredAddresses = Utils::FilterIpAddressesAny(ipAddressPool, 4u);

    // Assert
    EXPECT_EQ(filtredAddresses.size(), 3ul);
    ASSERT_TRUE(filtredAddresses.at(0) == Utils::ipAddress("1.2.3.4"));
    ASSERT_TRUE(filtredAddresses.at(1) == Utils::ipAddress("179.210.145.4"));
    ASSERT_TRUE(filtredAddresses.at(2) == Utils::ipAddress("219.4.120.135"));
}
