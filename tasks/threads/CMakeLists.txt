cmake_minimum_required(VERSION 3.7)
project(threads)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB LIB_SOURCES "src/*.cpp" "main.cpp" "include/*.h")

add_executable(threads ${LIB_SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} m pthread progbase-cpp progbase)