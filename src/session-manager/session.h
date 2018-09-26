/**
 * A Session starts with accepting the user's input, processing it, executing the
 * described commands ( queries and data formatting ) and then presenting the results
 * (query report).
 *
 * When a user runs the program, this Session object is created and destroyed when
 * the user is done with the current set of data.
 */

#ifndef TRAFFIC_LOGGER_SESSION_H
#define TRAFFIC_LOGGER_SESSION_H

#include "configurations.h"
#include <memory>

using std::unique_ptr;

namespace session {

    enum APPLICATION_MODES_ENUM{OFFLINE_JOB, /*SERVICE --//-- CONTINUOUS*/};

    /**
     * Contains:
     *      - configuration, used to describe where the HTTP logs are
     *          coming from;
     *      - any queries to be executed on top of this data;
     *      - mode in which the program should be ran ( service, one-time job );
     *      - any data transformation options that modify the original logs and
     * prepare it for storage.
     */
    class Session {
    public:
        Session(ILogProvider* log_provider, IQueryPool* queries = nullptr, IOutputStorage* output_details = nullptr);
    private:
        unique_ptr<ILogProvider> log_source;
        unique_ptr<IQueryPool> user_queries;
        unique_ptr<IOutputStorage> data_storage_location;
        APPLICATION_MODES_ENUM run_as;
    };  // class Session

}  // namespace session

#endif //TRAFFIC_LOGGER_SESSION_H
