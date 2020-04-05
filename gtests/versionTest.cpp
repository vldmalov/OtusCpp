#include "gtest/gtest.h"
#include "versionLib.h"

TEST(test_version, test_valid_version)
{
    ASSERT_GT(version(), 0);
}
