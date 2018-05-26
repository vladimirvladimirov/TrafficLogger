#include "simple-file-conveyer.h"
#include <exception>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using std::string;
using std::exception;

SimpleFileConveyer::SimpleFileConveyer(string file_location) {
   fin = new ifstream(file_location, std::ifstream::in);
    if (!fin->good()) {
        throw ConveyerException("Cannot read from file " + file_location);
    }
    buffer = new char[constants::MAX_HTTP_REQUEST_LENGTH];
}

char *SimpleFileConveyer::read_next_request_chars() {
    if (!fin->getline(buffer, constants::MAX_HTTP_REQUEST_LENGTH)) {
        if (!fin->eofbit) {
            throw ConveyerException("Error while reading HTTP request as char*.");
        }
    }
    return buffer;
}

string *SimpleFileConveyer::read_next_request_string() {
    std::string *next_line = new string();
    if (!std::getline(*fin, *next_line)) {
        if (!fin->eofbit) {
            throw ConveyerException("Error while reading HTTP request as string.");
        }
    }
    return next_line;
}