cmake_minimum_required(VERSION 3.16)
project(cqueue)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_executable(cqueue
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(cqueue
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)