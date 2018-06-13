cmake_minimum_required(VERSION 3.5.2)
project(xml)

set(CMAKE_C_FLAGS "-std=c99 -g -Werror -Wall -pedantic-errors")

include_directories(include)
include_directories(/usr/include/libxml2)

file(GLOB SOURCES "src/*.c" "main.c")

add_executable(xml ${SOURCES})
target_link_libraries(xml "-lxml2")