# server side
find_package(rpclib REQUIRED)
add_executable(${PROJECT_NAME}-server server.cpp)
target_link_libraries(${PROJECT_NAME}-server ncurses librpc.a)