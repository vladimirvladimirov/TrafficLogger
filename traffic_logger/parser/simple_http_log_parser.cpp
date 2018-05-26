//
// Created by vivanovv on 5/25/2018.
//

#include "simple_http_log_parser.h"
#include "http_log_parser.h"
#include "../conveyor/simple-file-conveyer.h"
#include <sstream>
#include <string>
#include <map>

using std::map;
using std::string;
using std::stringstream;

namespace utils {
    string get_key_for_pair_with_center(const string &request, int index) {
        string key = "";
        for (int i = index - 1; i >= 0 && request[i] != ' '; i--) {
            key.push_back(request[i]);
        }
        return string(key.rbegin(), key.rend());
    }

    string get_value_for_pair_with_center(const string &request, int index, int &end_index) {
        if (index == request.size() - 1) {
            throw ParserException("Plain text HTTP request ends with '='. Is this valid?");
        }
        char separator = ' ';
        int start_from = index;
        if (request[index + 1] == '"') {
            separator = '"';
            start_from = index + 2;
        } else {
            start_from = index + 1;
        }
        string value = "";
        for (int i = start_from, end_index = start_from;
             i < request.size() && request[i] != separator; i++, end_index++) {
            value.push_back(request[i]);
        }
        return value;
    }

}  // namespace utils

MAP* SimpleHttpLogParser::parse_http_request(const string &logged_request) {
    MAP *props = new MAP();

    /*
    stringstream ss(logged_request);
    if (!ss.good()) {
        throw new ParserException("Cannot parse request: " + logged_request);
    }

    string pair;
    while (ss >> pair) {
        string::size_type split_position = pair.find_first_of("=");
        if (split_position == string::npos) {
            throw new ParserException(logged_request + " is not a valid key-value pair!");
        }
        string key = pair.substr(0, split_position);
        string value = pair.substr(split_position+1);
//        (*props)[key] = value;
//        props->insert(std::make_pair(key, value));
    }
     // doesn't work because we have values with ' ' in them
     */

    int REQUEST_LENGTH = logged_request.size();

    if (REQUEST_LENGTH == constants::MAX_HTTP_REQUEST_LENGTH) {
        throw new ParserException("Warning: the size of the parser buffer might be smaller than needed.");
    }
    // Manual labour
    int current_index = -1;
    string key = "";
    string value = "";

    while (current_index < REQUEST_LENGTH) {
        current_index++;
        if (logged_request[current_index] == '=') {
            key = utils::get_key_for_pair_with_center(logged_request, current_index);
            int end_index = current_index;
            value = utils::get_value_for_pair_with_center(logged_request, current_index, end_index);
            (*props)[key] = value;
        }
    }

    return props;
}
