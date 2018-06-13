cmake_minimum_required(VERSION 3.5.1)
project(cpp)

set(CMAKE_CXX_FLAGS "-std=c++14 -g -Werror -Wall -pedantic-errors")

include_directories(include)

#include_directories(/usr/include/libxml2)

file(GLOB SOURCES "main.cpp" "src/*.cpp" "include/*.h")
add_executable(cpp ${SOURCES})
#add_library(practice ${SOURCES})
#target_link_libraries(practice "-lm -lprogbase -lcheck")
