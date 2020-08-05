# Set minimum version
cmake_minimum_required(VERSION 3.6)

# Set characteristics for project
project(less6 VERSION 0.0.0.1 LANGUAGES CXX)
#set(CMAKE_CXX_COMPILER_ID CLANG)

message(${CMAKE_CXX_COMPILER_ID})
# Defile variables
#set(PROJECT_SOURCES constexpr.cpp)

# The main program add_executable
add_executable(constexpr constexpr.cpp)
add_executable(inline inline.cpp)
add_executable(struct_bind structured_bindings.cpp)
add_executable(inits initializers.cpp)
add_executable(filesystem filesystem.cpp)
add_executable(ub ub.cpp)
add_executable(trigraph trigraph.cpp)

# Set targets properties for hello_cmake and tests projects
set_target_properties(constexpr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(inline PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(struct_bind PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(inits PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_compile_features(filesystem PUBLIC cxx_std_17)
set_target_properties(filesystem PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON )
target_link_libraries(filesystem stdc++fs)
set_target_properties(ub PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(trigraph PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON )


if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

#link_libraries(stdc++fs)


