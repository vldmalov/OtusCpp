add_library(mainLib "")
# add_library(mainLib versionLib.cpp)

message(STATUS "Running main library CMakeLists..")

set_target_properties(mainLib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_sources(
    mainLib
    PRIVATE versionLib.cpp
    # PUBLIC ${CMAKE_CURRENT_LIST_DIR}/versionLib.h
    )

target_include_directories(
    mainLib
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
    PRIVATE "${CMAKE_BINARY_DIR}" # version.h here
    )

if (MSVC)
    target_compile_options(mainLib PRIVATE
        /W4
    )
else ()
    target_compile_options(mainLib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()