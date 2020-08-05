cmake_minimum_required(VERSION 3.5)

project(09.templates)

add_executable(any any.cpp)
set_target_properties(any PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(begin begin.cpp)
set_target_properties(begin PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(metafunctions metafunctions.cpp)
set_target_properties(metafunctions PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(optional optional.cpp)
set_target_properties(optional PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(sfinae sfinae.cpp)
set_target_properties(sfinae PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(variant variant.cpp)
set_target_properties(variant PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)