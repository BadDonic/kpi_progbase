cmake_minimum_required(VERSION 3.5.1)
project(events)

set(CMAKE_C_FLAGS "-std=c99 -g -Werror -Wall -pedantic-errors")

include_directories(include)

file(GLOB SOURCES "main.c" "src/*.c")
add_executable(events ${SOURCES})

target_link_libraries(events "-lprogbase")
