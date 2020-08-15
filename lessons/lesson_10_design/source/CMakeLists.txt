cmake_minimum_required(VERSION 3.5)

project(10.design)

add_executable(map map.cpp)
set_target_properties(map PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(dry dry.cpp)
set_target_properties(dry PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(tda tda.cpp)
set_target_properties(tda PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(dependency_inversion dependency_inversion.cpp)
set_target_properties(dependency_inversion PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)