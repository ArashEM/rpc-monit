cmake_minimum_required(VERSION 3.14)
project(monit VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

add_subdirectory(server)
add_subdirectory(client)