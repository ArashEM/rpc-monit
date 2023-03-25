#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include <ncurses.h>
#include "rpc/client.h"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    rpc::client client{"127.0.0.1", rpc::constants::DEFAULT_PORT};
    ::initscr();

    //std::string name{client.call("name").as<std::string>()};
    //std::cout << "The name is: " << name << std::endl;

    for (size_t i{}; i < 40; i++) {
        int32_t cnt{client.call("cnt").as<int32_t>()};
        std::string msg {"The cnt is: "};
        msg += std::to_string(cnt);
        ::mvprintw(0, 0, msg.c_str());
        ::refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    ::endwin();
    return 0;
}