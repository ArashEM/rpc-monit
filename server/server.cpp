#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

#include "dataGen.hpp"
#include "dataGenMonit.hpp"

void workerThread(std::function<void(void)> f, bool& exitFlag) {
    while (!exitFlag) {
        f();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Arash::Phy phy{};
    Arash::Mac mac{};
    bool exitFlag{false};
    rpc::server srv{"0.0.0.0", rpc::constants::DEFAULT_PORT};
    srv.bind("data", [&]() {
        Arash::dataMonit data{phy.rxCounter(), phy.txCounter(), mac.rxCounter(),
                              mac.txCounter()};
        return data;
    });
    srv.async_run();

    std::thread phyWorker{workerThread, std::ref(phy), std::ref(exitFlag)};
    std::thread MacWorker{workerThread, std::ref(mac), std::ref(exitFlag)};
    std::this_thread::sleep_for(std::chrono::seconds(10));
    exitFlag = true;

    phyWorker.join();
    MacWorker.join();
}