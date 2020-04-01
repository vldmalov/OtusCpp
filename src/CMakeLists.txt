add_executable(ip_filter main.cpp)

message(STATUS "Running main project CMakeLists..")

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(ip_filter PRIVATE
    versionLib
    ipAddressesLib
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()