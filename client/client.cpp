#include "rpc/client.h"
#include <iostream>

int main(int argc, char* argv[]) {

    rpc::client client("127.0.0.1", rpc::constants::DEFAULT_PORT);

    int32_t cnt{client.call("cnt").as<int32_t>()};
    std::cout << "The cnt is: " << cnt << std::endl;

    std::string name{client.call("name").as<std::string>()};
    std::cout << "The name is: " << name << std::endl;
    return 0;
}