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
        using INDEX = Arash::stackData::INDEX;
        Arash::stackData data{client.call("data").as<Arash::stackData>()};
        std::string phyRx{"phy RX: " + std::to_string(data[INDEX::PHY_RX])};
        std::string phyTx{"phy TX: " + std::to_string(data[INDEX::PHY_TX])};
        ::mvprintw(0, 0, phyRx.c_str(), "%s");
        ::mvprintw(1, 0, phyTx.c_str(), "%s");
        ::refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    ::endwin();
    return 0;
}