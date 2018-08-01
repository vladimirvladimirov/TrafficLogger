#include "utils/properties-loader.h"

#include <iostream>
#include <string>
#include <c++/4.8.3/chrono>

using std::cerr;
using global::PropertiesLoader;

void print_time(string prefix);

int main() {

    try {
        const PropertiesLoader* props = PropertiesLoader::get_instance();
        map<string, string> m = props->get_all_properties();
        for (auto a : m) {
            std::cout << a.first << " : " << a.second << '\n';
        }
    } catch (const std::exception &x) {
        cerr << x.what() << '\n';
    }

    return 0;
}

void print_time(string prefix) {
    std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();

    // Print time using ctime
    std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
    std::cout << prefix << std::ctime(&time_now_t) << std::endl;
}