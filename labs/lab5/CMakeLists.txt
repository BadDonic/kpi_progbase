cmake_minimum_required(VERSION 3.5.1)
project(lab5)

set(CMAKE_C_FLAGS "-std=c99 -g -Werror -Wall -pedantic-errors")

include_directories(include)
include_directories(/usr/include/libxml2)
#add_custom_target(mytest COMMAND make -c)

file(GLOB SOURCES "main.c" "src/*.c" "include/*.h")
add_executable(lab5 ${SOURCES})
#add_library(practice STATIC ${SOURCES})
target_link_libraries(lab5 "-lprogbase -lcheck -lliblab5")
target_link_libraries(lab5 libjansson.so)
target_link_libraries(lab5 libxml2.so)

#install(
#        DIRECTORY include/     DESTINATION /usr/local/include
#        FILES_MATCHING PATTERN "*.h"
#)
#install(TARGETS practice DESTINATION /usr/local/lib)
