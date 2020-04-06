#pragma once

#include <string>

namespace versionLib
{
	std::string getFullVersion();

	size_t getMajorVersion();
	size_t getMinorVersion();
	size_t getPatchVersion();
}
