#include "gtest/gtest.h"
#include "versionLib.h"

TEST(test_version, test_valid_version)
{
	EXPECT_EQ(versionLib::getMajorVersion(), 0);
	EXPECT_EQ(versionLib::getMinorVersion(), 0);
	ASSERT_GT(versionLib::getPatchVersion(), 0);
}
