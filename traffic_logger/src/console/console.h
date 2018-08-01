#include "../utils/properties-loader.h"

#include <queue>

#ifndef TRAFFICLOGGER_CONSOLE_H
#define TRAFFICLOGGER_CONSOLE_H

namespace cmd_console {

    const std::string FILE_NAME = global::PropertiesLoader::get_instance()->get_property("command_history_file");
    const std::string PATH_TO_PROJECT_ROOT = "../";

    const int HISTORY_SIZE = std::stoi(global::PropertiesLoader::get_instance()->get_property("history_size"));

    /**
     * Interface for the console handling modules.
     * Should allow the following operations:
     *
     *      - reading from the console's input;
     *      - writing to the console's output;
     *      - reading commands from previous program executions from file;
     *      - saving commands from the current program execution to a file.
     */
    class IConsole {
    public:
        /**
         * @return the next sequence of 'active' characters at the moment in the console.
         */
        virtual string read_command() = 0;

        /**
         * Prints a message to the console. Used when printing outputs from commands or
         * notifications.
         */
        virtual void write(string) = 0;

        /**
         * Loads the list of already executed (correct) commands during previous runs of the
         * program from a file.
         */
        virtual void load_history() = 0;

        /**
         * Appends the correctly spelled commands from this session/program run to the file with
         * the command history.
         */
        virtual void save_history() = 0;
    };

    /**
     * Implements only the history-handling methods for a console.
     *
     * The meaning of "history" is "list of operations, successfully executed at previous program runs".
     */
    class IFileHistoryConsole : public IConsole {
    public:
        void load_history();

        void save_history();

    protected:
        IFileHistoryConsole(const string &path_to_file) {
            path_to_history_file = path_to_file;
            load_history();
        }

    protected:
        std::queue<string> commands;
        std::string path_to_history_file;
    };

    class SimpleConsole : public IFileHistoryConsole {
    public:
        static SimpleConsole *create_simple_cmd_console();

    private:
        SimpleConsole();

    };

}  // namespace cmd_console

#endif //TRAFFICLOGGER_CONSOLE_H
