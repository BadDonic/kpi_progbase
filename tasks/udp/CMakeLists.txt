cmake_minimum_required(VERSION 3.5.1)

project(client)
add_executable(${CMAKE_PROJECT_NAME} "client.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase)

project(server)
add_executable(${CMAKE_PROJECT_NAME} "server.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase)