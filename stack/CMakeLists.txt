cmake_minimum_required(VERSION 3.16)
project(cstack)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_executable(cstack
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(cstack
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)