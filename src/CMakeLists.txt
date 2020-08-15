add_executable(02_allocator main.cpp)

message(STATUS "Running main project CMakeLists..")

set_target_properties(02_allocator PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS 02_allocator RUNTIME DESTINATION bin)

if (MSVC)
    target_compile_options(02_allocator PRIVATE
        /W4
    )
else ()
    target_compile_options(02_allocator PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()