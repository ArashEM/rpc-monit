#include <iostream>

#include "rpc/server.h"

int main(int argc, char *argv[])
{
    // Create a server that listens on port 8080, or whatever the user selected
    rpc::server srv("0.0.0.0", rpc::constants::DEFAULT_PORT);

    return 0;
}