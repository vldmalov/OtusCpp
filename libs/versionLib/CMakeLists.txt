add_library(versionLib "")
# add_library(versionLib versionLib.cpp)

message(STATUS "Running main library CMakeLists..")

set_target_properties(versionLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_sources(
    versionLib
    PRIVATE versionLib.cpp
    # PUBLIC ${CMAKE_CURRENT_LIST_DIR}/versionLib.h
    )

target_include_directories(
    versionLib
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
    PRIVATE "${CMAKE_BINARY_DIR}" # version.h here
    )

if (MSVC)
    target_compile_options(versionLib PRIVATE
        /W4
    )
else ()
    target_compile_options(versionLib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()