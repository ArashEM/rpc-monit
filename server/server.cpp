#include <chrono>
#include <iostream>
#include <thread>

#include "dataGen.hpp"
#include "dataGenMonit.hpp"

void workerThread(Arash::dataGen& obj, bool& exitFlag) {
    while (!exitFlag) {
        obj();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Arash::dataGen gen{};
    Arash::dataGenMonit genMon{gen, "gen"};
    bool exitFlag{false};

    std::thread worker{workerThread, std::ref(gen), std::ref(exitFlag)};
    std::this_thread::sleep_for(std::chrono::seconds(60));
    exitFlag = true;
    worker.join();
}