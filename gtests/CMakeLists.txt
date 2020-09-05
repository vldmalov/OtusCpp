add_executable(gtest_version versionTest.cpp)

message(STATUS "Running gtests CMakeLists..")

set_target_properties(gtest_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

message(STATUS "---------------------")
message(STATUS "PROJECT_SOURCE_DIR:     ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR:     ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_BINARY_DIR:       ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "---------------------")

include(${PROJECT_SOURCE_DIR}/cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

# target_include_directories(gtest_version
# 	PRIVATE ${PROJECT_SOURCE_DIR}/data
# )
# add_subdirectory(${PROJECT_SOURCE_DIR}/data)

target_link_libraries(gtest_version
	gtest_main
    versionLib
    ipAddressesLib
    )

if (MSVC)
    target_compile_options(gtest_version PRIVATE
        /W4
    )
else ()
    target_compile_options(gtest_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

