message(STATUS "Running gtests CMakeLists..")

add_executable(
    unitTests
    versionTest.cpp
)

set_target_properties(unitTests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

message(STATUS "---------------------")
message(STATUS "PROJECT_SOURCE_DIR:       ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR:       ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_BINARY_DIR:         ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_LIST_DIR:   ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "---------------------")

add_subdirectory(
    "${PROJECT_SOURCE_DIR}/frameworks/googletest" build
)

target_include_directories( unitTests PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
)

target_link_libraries(unitTests PRIVATE
    gtest
    gtest_main
    versionLib
    ipAddressesLib
    )

if (MSVC)
    target_compile_options(unitTests PRIVATE
        /W4
    )
else ()
    target_compile_options(unitTests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

