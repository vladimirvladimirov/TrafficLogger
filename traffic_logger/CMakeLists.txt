cmake_minimum_required(VERSION 3.10)
project(traffic_logger)

set(CMAKE_CXX_STANDARD 11)

add_executable(traffic_logger main.cpp src/utils/properties_loader.cpp)