#include "conveyor/simple-file-conveyer.h"
#include "parser/simple_http_log_parser.h"

#include <iostream>
#include <string>
#include <c++/4.8.3/chrono>

using std::cerr;

void print_time(string prefix);

int main() {
    std::cin.sync_with_stdio(false);
    string test_log = "X:\\git repos\\traffic_logger\\test_data\\sample_0.txt";
    string real_log_ssd = "C:\\Users\\vivanovv\\Documents\\logs\\sample_1.txt";
    string real_log_hdd = "E:\\logs\\sample_1.txt";
    SimpleFileConveyer reader(real_log_ssd);
    SimpleHttpLogParser parser;

    print_time("Start: ");

    do {
        try {
            unique_ptr<string> request(reader.read_next_request_string());
            unique_ptr<MAP> props(parser.parse_http_request(*request));
            for(auto pair : *props) {
                std::cout << "!--" << pair.first << " : '" << pair.second << "' --! ";
            }
            getchar();
        } catch (ConveyerException e) {
            cerr << e.what() << '\n';
            break;
        } catch (ParserException e) {
            cerr << e.what() << '\n';
            break;
        }

    } while (reader.is_ok());

    print_time("End: ");

    return 0;
}

void print_time(string prefix) {
    std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();

    // Print time using ctime
    std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
    std::cout << prefix << std::ctime(&time_now_t) << std::endl;
}