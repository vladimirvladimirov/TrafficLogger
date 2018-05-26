//
// Created by vivanovv on 5/25/2018.
//

#ifndef TRAFFIC_LOGGER_SIMPLE_HTTP_LOG_PARSER_H
#define TRAFFIC_LOGGER_SIMPLE_HTTP_LOG_PARSER_H

#include "http_log_parser.h"
#include <string>
#include <map>

using std::map;
using std::string;

// TODO try making the key an enum value
typedef map<string,string> MAP;

/**
 * Simple plain text parser for logged HTTP requests that returns the parsed request
 * as map of Key-Value pairs.
 */
class SimpleHttpLogParser : public parser::HttpLogParser<MAP> {
public:
    MAP* parse_http_request(const string& logged_request);
};

#endif //TRAFFIC_LOGGER_SIMPLE_HTTP_LOG_PARSER_H