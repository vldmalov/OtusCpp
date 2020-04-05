add_executable(helloworld_cli main.cpp)

message(STATUS "Running main project CMakeLists..")

set_target_properties(helloworld_cli PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(helloworld_cli PRIVATE
    mainLib
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()