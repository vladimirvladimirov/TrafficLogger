//
// Created by vivanovv on 7/31/2018.
//

#ifndef TRAFFICLOGGER_CONSOLE_H
#define TRAFFICLOGGER_CONSOLE_H

namespace cmd_console {

    /**
     * Interface for the console handling modules.
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
     */
    class IFileHistoryConsole : public IConsole {
    public:
        void load_history();

        void save_history();
    };

    class SimpleConsole : public IFileHistoryConsole {

    };

}  // namespace cmd_console

#endif //TRAFFICLOGGER_CONSOLE_H
