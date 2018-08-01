#include "console.h"

#include <fstream>
#include <memory>

using std::ofstream;

void cmd_console::IFileHistoryConsole::load_history() {
    ifstream fin(path_to_history_file);
    if (!fin.good()) {
        throw std::runtime_error("Error reading history file.");
    }
    string command;
    while (std::getline(fin, command, '\n')) {
        commands.push(command);
    }
    fin.close();
}

void cmd_console::IFileHistoryConsole::save_history() {
    ofstream fout(path_to_history_file);
    if (!fout.good()) {
        throw std::runtime_error("Error writing to history file.");
    }
    while (commands.size() > cmd_console::HISTORY_SIZE) {
        commands.pop();
    }
    while (!commands.empty()) {
        fout << commands.front() << '\n';
        commands.pop();
    }
    fout.close();
}

cmd_console::SimpleConsole::SimpleConsole() : IFileHistoryConsole("../history.txt") {}
