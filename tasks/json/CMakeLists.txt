cmake_minimum_required(VERSION 3.5.1)
project(json)

set(CMAKE_C_FLAGS "-std=c99 -g -Werror -Wall -pedantic-errors")

include_directories(include)

#include_directories(/usr/include/libxml2)

file(GLOB SOURCES "main.c" "src/*.c" "include/*.h")
add_executable(json ${SOURCES})
#add_library(practice ${SOURCES})
target_link_libraries(json "-ljansson")

#install(
#        DIRECTORY include/     DESTINATION /usr/local/include
#        FILES_MATCHING PATTERN "*.h"
#)
#install(TARGETS practice DESTINATION /usr/local/lib)
