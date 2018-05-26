cmake_minimum_required(VERSION 3.10)
project(traffic_logger)

set(CMAKE_CXX_STANDARD 11)

add_executable(traffic_logger main.cpp conveyor/conveyer.h conveyor/simple-file-conveyer.h conveyor/simple-file-conveyer.cpp parser/http_log_parser.h parser/simple_http_log_parser.cpp parser/simple_http_log_parser.h)