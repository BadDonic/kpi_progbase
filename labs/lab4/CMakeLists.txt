cmake_minimum_required(VERSION 3.5.1)
project(lab4)

set(CMAKE_C_FLAGS "-std=c99 -g -Werror -Wall -pedantic-errors")

include_directories(include)

#include_directories(/usr/include/libxml2)
#add_custom_target(mytest COMMAND make -c)

file(GLOB SOURCES "main.c" "src/*.c")
add_executable(lab4 ${SOURCES})
#add_library(practice STATIC ${SOURCES})
target_link_libraries(lab4 "-lprogbase -lcheck")

#install(
#        DIRECTORY include/     DESTINATION /usr/local/include
#        FILES_MATCHING PATTERN "*.h"
#)
#install(TARGETS practice DESTINATION /usr/local/lib)
