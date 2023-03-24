#include <iostream>
#include <chrono>
#include <thread>

#include "dataGen.hpp"
#include "dataGenMonit.hpp"

int main(int argc, char* argv[])
{
    Arash::dataGen gen{};
    Arash::dataGenMonit genMon {gen, "gen"};
}