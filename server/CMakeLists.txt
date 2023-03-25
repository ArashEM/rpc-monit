# server side
find_package(rpclib REQUIRED)
set(TARGET_NAME ${PROJECT_NAME}-server)
add_executable(${TARGET_NAME} server.cpp)
target_link_libraries(${TARGET_NAME} librpc.a)
target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)