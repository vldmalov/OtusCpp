cmake_minimum_required(VERSION 3.5)

project(03.cpp)

add_executable(decltype decltype.cpp)
add_executable(lambda lambda.cpp)
add_executable(rvo rvo.cpp)
add_executable(values values.cpp)
add_executable(move move.cpp)
add_executable(vt vt.cpp)
add_executable(perfect perfect.cpp)
add_executable(aggregate aggregate.cpp)

set_target_properties(decltype lambda PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

set_target_properties(rvo values move vt PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )
