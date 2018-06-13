cmake_minimum_required(VERSION 3.5.1)
project(callback)

set(CMAKE_C_FLAGS "-std=c99 -g -Werror -Wall -pedantic-errors")

file(GLOB SOURCES "main.c")
add_executable(callback ${SOURCES})
#target_link_libraries(callback "-lm")