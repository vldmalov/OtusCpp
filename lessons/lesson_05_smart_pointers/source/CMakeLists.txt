cmake_minimum_required(VERSION 3.5)

project(07.smart_ptr)

add_executable(scope scope.cpp)
set_target_properties(scope PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(custom_unique custom_unique.cpp)
set_target_properties(custom_unique PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(unique_ptr unique_ptr.cpp)
set_target_properties(unique_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(custom_shared custom_shared.cpp)
set_target_properties(custom_shared PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(shared_ptr shared_ptr.cpp)
set_target_properties(shared_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(enable_shared_from_this enable_shared_from_this.cpp)
set_target_properties(enable_shared_from_this PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(weak_ptr weak_ptr.cpp)
set_target_properties(weak_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(arrays arrays.cpp)
set_target_properties(arrays PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(cycle_ref cycle_ref.cpp)
set_target_properties(cycle_ref PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)