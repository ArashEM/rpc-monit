cmake_minimum_required(VERSION 3.14)
project(monit VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
find_package(rpclib REQUIRED)

# server side
add_executable(${PROJECT_NAME}-server server.cpp)
target_link_libraries(${PROJECT_NAME}-server ncurses librpc.a)

#client side
add_executable(${PROJECT_NAME}-client client.cpp)
target_link_libraries(${PROJECT_NAME}-client librpc.a)