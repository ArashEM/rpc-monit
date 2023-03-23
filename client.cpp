#include <iostream>
#include "rpc/client.h"

int main(int argc, char *argv[])
{
    rpc::client client("127.0.0.1", rpc::constants::DEFAULT_PORT);
    auto result = client.call("cnt").as<int>();
    std::cout << "The result is: " << result << std::endl;
    result = client.call("cnt").as<int>();
    std::cout << "The result is: " << result << std::endl;
    result = client.call("cnt").as<int>();
    std::cout << "The result is: " << result << std::endl;
    result = client.call("cnt").as<int>();
    std::cout << "The result is: " << result << std::endl;

    return 0;
}