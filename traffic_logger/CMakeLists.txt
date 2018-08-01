cmake_minimum_required(VERSION 3.10)
project(traffic_logger)

set(CMAKE_CXX_STANDARD 11)

set(UTILS src/utils/properties_loader.cpp)
set(CONSOLE src/console/console.cpp)

add_executable(traffic_logger src/main.cpp ${UTILS} ${CONSOLE})