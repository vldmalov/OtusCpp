cmake_minimum_required(VERSION 3.5)

project(02.cpp14)

add_executable(auto auto.cpp source.cpp)
add_executable(decltype decltype.cpp)
add_executable(lambda lambda.cpp)
add_executable(tuple tuple.cpp)

if (MSVC)
    target_compile_options(auto PRIVATE
        /W4
    )
    target_compile_options(decltype PRIVATE
        /W4
    )
    target_compile_options(lambda PRIVATE
        /W4
    )
    target_compile_options(tuple PRIVATE
        /W4
    )
else ()
    target_compile_options(auto PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(decltype PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lambda PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(tuple PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()