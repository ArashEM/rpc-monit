#include <iostream>
#include <chrono>

#include <ncurses.h>

#include "rpc/server.h"

void foo()
{
    std::cout << "foo was called!" << std::endl;
}

void bad(int x)
{
    if (x == 5)
    {
        throw std::runtime_error("x == 5. I really don't like 5.");
    }
}

int32_t cnt(void)
{
    static int32_t cnt{};
    return cnt++;
}

int main()
{

    // init screen and sets up screen
    initscr();

    // Create a server that listens on port 8080, or whatever the user selected
    rpc::server srv("0.0.0.0", rpc::constants::DEFAULT_PORT);

    // Binding the name "foo" to free function foo.
    // note: the signature is automatically captured
    srv.bind("foo", &foo);

    // Binding a lambda function to the name "add".
    srv.bind("add", [](int a, int b)
             { return a + b; });

    srv.bind("cnt", &cnt);

    // Throwing an exception will cause the server to write
    // an error response. This call will make it also
    // suppress the exception (note that this is not default
    // because this behavior might hide errors in the
    // code).
    srv.suppress_exceptions(true);
    srv.bind("bad", &bad);

    printw("I am here...");
    refresh();
    // pause the screen output
    getch();
    // deallocates memory and ends ncurses
    endwin();

    // Run the server loop.
    srv.run();

    return 0;
}