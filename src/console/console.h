/**
 * A middleware module that accepts user configuration and delegates it to the
 * session manager.
 *
 * The configuration from the user can be set up using the standard input/output
 * or be read from file.
 */

#ifndef TRAFFIC_LOGGER_CONSOLE_H
#define TRAFFIC_LOGGER_CONSOLE_H

#include <iostream>
#include <string>

namespace console {

    /**
     * Interface that provides the very basic functionalities for a module
     * that handles user input.
     */
    class IConsole {
    public:
        virtual ~IConsole() {};

        virtual std::string read_next_line() = 0;

        virtual int write_message(const std::string &msg) = 0;
    };

    class GenericConsole : public IConsole {
    public:
        GenericConsole(std::istream &in, std::ostream &out);

        virtual ~GenericConsole();

        virtual std::string read_next_line();

        virtual int write_message(const std::string &msg);

    protected:

        std::istream &in;
        std::ostream &out;
    };

    /**
     * Simple implementation of IConsole, used to read and write from/to
     * stdin and stdout.
     */
    class SimpleConsole : public GenericConsole {
    public:
        SimpleConsole();

        virtual ~SimpleConsole();
    };

}  // namespace console

#endif //TRAFFIC_LOGGER_CONSOLE_H
