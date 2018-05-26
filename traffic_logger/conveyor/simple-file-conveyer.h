//
// Created by vivanovv on 5/25/2018.
//

#ifndef TRAFFIC_LOGGER_SIMPLEFILECONVEYER_H
#define TRAFFIC_LOGGER_SIMPLEFILECONVEYER_H

#include "conveyer.h"
#include <fstream>
#include <c++/4.8.3/bits/unique_ptr.h>
#include <c++/4.8.3/iostream>

using std::ifstream;
using std::unique_ptr;

namespace constants {
    const unsigned int MAX_HTTP_REQUEST_LENGTH = 4096 + 100; // B
}  // namespace constants

/**
 * Simple class that reads the HTTP traffic log from file.
 */
class SimpleFileConveyer : public SynchroniousConveyer {
public:

    /**
     * Opens up input file stream to read from the file on the specified location.
     *
     * Doesn't check for validity; the caller should make sure he passes a
     * destionation to already existing file.
     *
     * @param file_location - file that contains logs from the HTTP traffic to the server.
     */
    SimpleFileConveyer(string file_location);

    /**
     * @return The next logged HTTP request as plain string.
     */
    string *read_next_request_string();

    /**
     * @return Same as above, except the returned results comes as C-style string, instead of C++ such.
     */
    virtual char *read_next_request_chars();

    bool is_ok() {
        return fin->good();
    }

private:
    ifstream *fin;
    char* buffer;
};

#endif //TRAFFIC_LOGGER_SIMPLEFILECONVEYER_H
