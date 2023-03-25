#include "rpc/client.h"
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    rpc::client client{"127.0.0.1", rpc::constants::DEFAULT_PORT};

    std::string name{client.call("name").as<std::string>()};
    std::cout << "The name is: " << name << std::endl;

    for (size_t i{}; i < 40; i++) {
        int32_t cnt{client.call("cnt").as<int32_t>()};
        std::cout << "The cnt is: " << cnt << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}