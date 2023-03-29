#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include <ncurses.h>
#include "rpc/client.h"

#include "../server/stackData.hpp"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    rpc::client client{"127.0.0.1", rpc::constants::DEFAULT_PORT};
    ::initscr();

    for (size_t i{}; i < 40; i++) {
        Arash::stackData data{client.call("data").as<Arash::stackData>()};
        std::string msg{"The cnt is: "};
        msg += std::to_string(data[Arash::stackData::INDEX::MAC_RX]);
        ::mvprintw(0, 0, msg.c_str());
        ::refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    ::endwin();
    return 0;
}