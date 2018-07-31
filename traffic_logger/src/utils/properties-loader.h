//
// Created by vivanovv on 8/1/2018.
//

#ifndef TRAFFIC_LOGGER_PROPERTIES_LOADER_H
#define TRAFFIC_LOGGER_PROPERTIES_LOADER_H

#include <c++/4.8.3/string>
#include <c++/4.8.3/map>
#include <c++/4.8.3/memory>
#include <c++/4.8.3/fstream>

using std::string;
using std::map;
using std::ifstream;

namespace global {

    /**
     * Name of the file in which project-specific properties will be stored.
     */
    const static string LOCAL_PROPS_FILENAME = "local.properties";

    /**
     * Loads a set of key:value pairs from a file.
     *
     * The format of the file must obey the following rules:
     *      - every KV pair should be on separate line;
     *      - every line should be in the format of "key=value", no quotes and no intervals; No
     *          other limitations on special symbols ( be careful with filenames though ).
     *      - every line should be less than 2000 symbols (not enforced).
     *
     * In case any of the lines is malformed, an instance of runtime_error() will be thrown.
     */
    class PropertiesLoader {
    public:
        static PropertiesLoader *get_instance() {
            return singleton.get();
        }

        const map<string, string> &get_all_properties() const {
            return local_properties;
        }

        const string &get_property(const string &key) {
            return local_properties[key];
        }

    private:
        PropertiesLoader() {
            ifstream fin(LOCAL_PROPS_FILENAME);
            if (!fin.good()) {
                throw new std::runtime_error("Error opening the file with local properties.");
            }
            string key, val;
            while (std::getline(std::getline(fin, key, '=') >> std::ws, val))
                local_properties[key] = val;
        }

        map<string, string> local_properties;

        static std::unique_ptr<PropertiesLoader> singleton;
    };

}  // namespace global

#endif //TRAFFIC_LOGGER_PROPERTIES_LOADER_H
