cmake_minimum_required(VERSION 3.16)
project(test)

set(CMAKE_C_STANDARD 11)

add_subdirectory(tree)
add_subdirectory(queue)


add_executable(test
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

target_link_libraries(test
    ctree
    cqueue
)