cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

message(STATUS "---------------------")
message(STATUS "CMAKE_BINARY_DIR:       ${CMAKE_BINARY_DIR}")
message(STATUS "PROJECT_BINARY_DIR:     ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "---------------------")

set(BUILD_VERSION 0.9.9)
if($ENV{TRAVIS_BUILD_NUMBER})
	message(STATUS "Travis build number = " $ENV{TRAVIS_BUILD_NUMBER})
	set(BUILD_VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	message(WARNING "TRAVIS_BUILD_NUMBER env variable doesn't exist")
endif()

project(helloworld VERSION ${BUILD_VERSION})

configure_file(version.h.in version.h)

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(tests)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT vldmalov@gmail.com)

include(CPack)

enable_testing()

add_test(test_version tests/test_version)
