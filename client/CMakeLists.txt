#client side
set(TARGET_NAME ${PROJECT_NAME}-client)
add_executable(${TARGET_NAME} client.cpp)
target_link_libraries(${TARGET_NAME} librpc.a)
target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)