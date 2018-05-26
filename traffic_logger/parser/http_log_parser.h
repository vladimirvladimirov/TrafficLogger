//
// Created by vivanovv on 5/25/2018.
//

#ifndef TRAFFIC_LOGGER_HTTPLOGPARSER_H
#define TRAFFIC_LOGGER_HTTPLOGPARSER_H

#include <c++/4.8.3/string>
#include <exception>
#include <map>

using std::exception;
using std::string;
using std::map;

namespace parser {

/**
 * Interface for the parsing instrumentarium in this module.
 *
 * ParsedRequest is the object to which a logged request should be parsed.
 *
 * Examples include, but are not limited to types, representing: collections
 * of key-value pairs, plain string in JSON format, enum-to-value maps and so on.
 */
template < class ParsedRequest >
class HttpLogParser {
    ParsedRequest* parse_http_request(const string& logged_request);
};

}  // namespace parser


/**
 * Generic exception that will be thrown whenever an error in the parser module occurs.
 */
class ParserException : public exception {
public:
    ParserException(const string err_message) : error(err_message) {}

    virtual const char *what() const throw() {
        return error.c_str();
    }

private:
    const string error;
};

#endif //TRAFFIC_LOGGER_HTTPLOGPARSER_H
