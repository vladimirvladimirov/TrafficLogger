cmake_minimum_required(VERSION 3.10)
project(traffic_logger)

set(CMAKE_CXX_STANDARD 14)

# External libraries
set(GTEST_ROOT "C:/Program Files (x86)/googletest-distribution")
set(GTEST_LIB_FOLDER "${GTEST_ROOT}/lib")
set(GTEST_HEADERS_LOCATION "${GTEST_ROOT}/include/gtest")

include_directories(${GTEST_HEADERS_LOCATION})

# Modules
add_library(console src/console/console.cpp src/console/console.h)

# Executables
add_executable(traffic_logger src/main.cpp)
add_executable(unit_tests test/unit_tests.cpp ${GTEST_SRCS})

# Linking external libs
target_link_libraries(unit_tests PUBLIC "${GTEST_LIB_FOLDER}/libgtestd.a")
target_link_libraries(traffic_logger console)
