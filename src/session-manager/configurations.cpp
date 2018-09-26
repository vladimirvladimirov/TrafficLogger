//
// Created by vivanovv on 9/26/2018.
//

#include "configurations.h"
#include <string>
#include <vector>

using std::vector;

namespace session {

    StaticStringQueryPool::StaticStringQueryPool(const vector <std::string> &user_queries) : queries(user_queries) {}

    StaticStringQueryPool::StaticStringQueryPool(int max_query_size) { queries.resize(max_query_size); }
}  // namespace session
