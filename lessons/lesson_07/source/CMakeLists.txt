cmake_minimum_required(VERSION 3.5)

project(05.cpp17)

add_executable(ctor ctor.cpp)

set_target_properties(ctor PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(lambda lambda.cpp)

set_target_properties(lambda PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(fold fold.cpp)

set_target_properties(fold PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(attributes attributes.cpp)

set_target_properties(attributes PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(trigraph trigraph.cpp)

set_target_properties(trigraph PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        )

add_executable(structured_bindings structured_bindings.cpp)

set_target_properties(structured_bindings PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

#if (NOT MSVC)
add_executable(auto_template auto_template.cpp)

set_target_properties(auto_template PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(deduction deduction.cpp)

set_target_properties(deduction PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
#endif()