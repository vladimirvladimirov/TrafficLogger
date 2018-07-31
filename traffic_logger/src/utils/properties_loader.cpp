#include "properties-loader.h"

namespace global {
    std::unique_ptr<PropertiesLoader> PropertiesLoader::singleton(new PropertiesLoader());

}  // namespace global