#include <iostream>
#include <mmc.h>
#include "console/console.h"

using std::cin;
using std::cout;

using console::SimpleConsole;

int main() {

    console::IConsole *c = new SimpleConsole();
    std::string input;

    do {
        input = c->read_next_line();
        c->write_message(input + "\n");
    } while (input != "quit");

    return 0;
}