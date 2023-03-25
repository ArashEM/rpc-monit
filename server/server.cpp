#include <chrono>
#include <iostream>
#include <thread>

#include "dataGen.hpp"
#include "dataGenMonit.hpp"

int main(int argc, char* argv[]) {
    Arash::dataGen gen{};
    Arash::dataGenMonit genMon{gen, "gen"};

    std::this_thread::sleep_for(std::chrono::seconds(10));
}