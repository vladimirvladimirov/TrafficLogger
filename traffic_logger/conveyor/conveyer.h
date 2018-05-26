//
// Created by vivanovv on 5/25/2018.
//

#ifndef TRAFFIC_LOGGER_CONVEYER_H
#define TRAFFIC_LOGGER_CONVEYER_H

#include <exception>
#include <string>

using std::string;
using std::exception;

/**
 * Interface for sequental reading of data from HTTP traffic logs.
 */
class SynchroniousConveyer {
public:
    /**
     * @return The string representation of the next chronologically served HTTP request by the server.
     */
    virtual string* read_next_request_string() = 0;

    /**
     * @return Same as above, except the returned results comes as C-style string, instead of C++ such.
     */
    virtual char *read_next_request_chars() = 0;
};

/**
 * Generic exception that will be thrown whenever an error in the conveyer side occurs.
 */
class ConveyerException : public exception {
public:
    ConveyerException(const string err_message) : error(err_message) {}

    virtual const char *what() const throw() {
        return error.c_str();
    }

private:
    const string error;
};

#endif //TRAFFIC_LOGGER_CONVEYER_H
