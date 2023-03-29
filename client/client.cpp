#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include <ncurses.h>
#include "rpc/client.h"

#include "../server/dataGenMonit.hpp"
#include "../server/stackData.hpp"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    rpc::client client{"127.0.0.1", rpc::constants::DEFAULT_PORT};
    ::initscr();

    //std::string name{client.call("name").as<std::string>()};
    //std::cout << "The name is: " << name << std::endl;

    for (size_t i{}; i < 40; i++) {
        Arash::dataMonit data{client.call("data").as<Arash::dataMonit>()};
        std::string msg{"The cnt is: "};
        msg += std::to_string(data.m_phyRxCounter);
        ::mvprintw(0, 0, msg.c_str());
        ::refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    ::endwin();
    return 0;
}