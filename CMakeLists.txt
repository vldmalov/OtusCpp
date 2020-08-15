cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(BUILD_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
	message(STATUS "Travis build number = " $ENV{TRAVIS_BUILD_NUMBER})
	set(BUILD_VERSION $ENV{TRAVIS_BUILD_NUMBER})
else()
	message(WARNING "TRAVIS_BUILD_NUMBER env variable doesn't exist")
endif()

project(02_allocator VERSION 0.0.${BUILD_VERSION})
unset(BUILD_VERSION)

message(STATUS "---------------------")
message(STATUS "PROJECT_SOURCE_DIR:     ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR:     ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_BINARY_DIR:       ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "---------------------")

add_subdirectory(src)

target_sources(02_allocator
    PRIVATE main.cpp
    PRIVATE customAllocator.h
    PRIVATE coloredCout.h
)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT vldmalov@gmail.com)

include(CPack)
