#include <string>
#include "console.h"

namespace console {

    std::string GenericConsole::read_next_line() {
        std::string result;
        std::getline(in, result);
        return result;
    };

    int GenericConsole::write_message(const std::string &msg) {
        // TODO add logger and error checks when handling the streams
        out << msg;
    };

    GenericConsole::~GenericConsole() {}

    GenericConsole::GenericConsole(std::istream& in2, std::ostream& out2) : in(in2), out(out2) {}

    SimpleConsole::~SimpleConsole() {}

    SimpleConsole::SimpleConsole() : GenericConsole(std::cin, std::cout) {}

}  // namespace console