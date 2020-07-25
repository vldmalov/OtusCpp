add_library(ipAddressesLib "")
# add_library(ipAddressesLib ipAddresses.cpp)

message(STATUS "Running ipAddresses library CMakeLists..")

set_target_properties(ipAddressesLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_sources(
    ipAddressesLib
    PRIVATE ipAddresses.cpp
    PRIVATE ipAddresses.h
    # PUBLIC ${CMAKE_CURRENT_LIST_DIR}/ipAddresses.h
    )

target_include_directories(
    ipAddressesLib
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
    )

if (MSVC)
    target_compile_options(ipAddressesLib PRIVATE
        /W4
    )
else ()
    target_compile_options(ipAddressesLib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()