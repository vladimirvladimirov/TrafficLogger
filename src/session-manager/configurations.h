/**
 * Contains objects that describe the user's input. These include:
 *
 *      * source of the log data ( file, remote file, service...) and data format
 *      * queries to execute on the data
 *      * to which allowed data format should the raw logs be converted and where
 *          to be saved on the local FS.
 */

#ifndef TRAFFIC_LOGGER_CONFIGURATIONS_H
#define TRAFFIC_LOGGER_CONFIGURATIONS_H

#include <string>
#include <vector>

namespace session {

    /**
     * Contains all allowed formats in which the HTTP logs can be read.
     *
     * The default input format is PLAIN_TEXT.
     */
    enum ALLOWED_INPUT_FORMATS_ENUM {
        PLAIN_TEXT, JSON, COLUMN_IO_IN
    };

    /**
     * Contains all allowed formats in which the HTTP log data can be converted.
     */
    enum SUPPORTED_OUTPUT_FORMATS_ENUM {
        COLUMN_IO_OUT, COLUMN_IO_COMPRESSED_OUT
    };

    /**
     * Interface for the place where logs will be read from. Some examples include:
     *      * locally stored file;
     *      * remote location;
     *      * service or application.
     *
     * It also contains information about what the data format is (key-value pairs,
     * JSON, RecordIO, ColumnIO, etc ).
     *
     * The default input format is PLAIN_TEXT.
     */
    class ILogProvider {
    protected:
        ILogProvider(ALLOWED_INPUT_FORMATS_ENUM data_format = PLAIN_TEXT) : input_format(data_format) {}

        ALLOWED_INPUT_FORMATS_ENUM input_format;
    };  // class ILogProvider

    /**
     * Used to show that the logs should be read from a file on the local storage
     * system.
     *
     * file_location is the file path + file name to the log file in the local FS.
     */
    class LocalFileProvider : public ILogProvider {
    public:
        LocalFileProvider(std::string file) : file_location(file) {}

        const std::string &get_file_location() const { return file_location; }

    private:
        std::string file_location;
    };  // class LocalFileProvider

    /**
     * Interface for the objects that will represent user queries. Such
     * representations may be (but are not limited to):
     *
     *      - plain strings;
     *      - prefix/postfix binary tree notation;
     *      - some other data structure representations of Query Language expressions.
     */
    class IQueryPool {
    };

    /**
     * Every single query is represented as simple string. No queries can be added
     * or removed during runtime.
     *
     * In future we may think about representing it in another way, such as
     * postfix/prefix notation, etc...
     */
    class StaticStringQueryPool : public IQueryPool {
    public:
        StaticStringQueryPool(const std::vector <std::string> &user_queries);
        StaticStringQueryPool(int max_query_size);

    protected:
        std::vector <std::string> queries;
    };  // class StaticStringQueryPool

    /**
     * Allows the execution of a single query at a time.
     */
    class SingleQuery : public StaticStringQueryPool {
    public:
        SingleQuery(std::string query) : StaticStringQueryPool(1) { queries.push_back(query); }

        std::string get_query() const { return queries[0]; }
    };  // class SingleQuery

    /**
     * Defines the place and format in which the HTTP logs should be converted, if needed,
     * and written.
     */
    class IOutputStorage {
    public:
        IOutputStorage(SUPPORTED_OUTPUT_FORMATS_ENUM data_format) : output_format(data_format) {};
    protected:
        SUPPORTED_OUTPUT_FORMATS_ENUM output_format;
    };  // class IOutputStorage

    /**
     * Defines the output format and the location where the raw logs should be written after
     * getting converted to the desired format.
     *
     * If the file doesn't exist, this will try to create it. If it fails - not sure what should happen atm.
     */
    class LocalFileStorage : public IOutputStorage {
    public:
        LocalFileStorage(SUPPORTED_OUTPUT_FORMATS_ENUM data_format, std::string file) :
                IOutputStorage(data_format), file_location(file) {};
    private:
        std::string file_location;
    };  // class LocalFileStorage

}  // namespace session

#endif //TRAFFIC_LOGGER_CONFIGURATIONS_H
