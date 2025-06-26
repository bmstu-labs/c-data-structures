cmake_minimum_required(VERSION 3.16)
project(ctree)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library(ctree STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(ctree
    cqueue
)

target_include_directories(ctree
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)