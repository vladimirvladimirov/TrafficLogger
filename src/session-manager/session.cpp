#include "session.h"

namespace session {

    Session::Session(session::ILogProvider *log_provider, session::IQueryPool *queries,
                     session::IOutputStorage *output_details) : log_source(log_provider), user_queries
                     (queries),
                     data_storage_location(output_details), run_as(OFFLINE_JOB) {}


}  // namespace session
