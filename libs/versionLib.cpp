#include "versionLib.h"

#include "version.h"

#include <sstream>

namespace versionLib
{
	std::string getFullVersion()
	{
		std::stringstream ss;
		ss	<< PROJECT_VERSION_MAJOR << "."
			<< PROJECT_VERSION_MINOR << "."
			<< PROJECT_VERSION_PATCH;
		return ss.str();
	}

	size_t getMajorVersion()
	{
		return PROJECT_VERSION_MAJOR;
	}

	size_t getMinorVersion()
	{
		return PROJECT_VERSION_MINOR;
	}

	size_t getPatchVersion()
	{
		return PROJECT_VERSION_PATCH;
	}
}