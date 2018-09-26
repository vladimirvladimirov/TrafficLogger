cmake_minimum_required(VERSION 3.10)
project(traffic_logger)

set(CMAKE_CXX_STANDARD 14)

# External libraries
set(GTEST_ROOT "C:/Program Files (x86)/googletest-distribution")
set(GTEST_LIB_FOLDER "${GTEST_ROOT}/lib")
set(GTEST_HEADERS_LOCATION "${GTEST_ROOT}/include/gtest")

include_directories(${GTEST_HEADERS_LOCATION})
include_directories("./src/session-manager")
include_directories("./src/console")

# Modules and internal libraries
file(GLOB CONSOLE_SRCS "src/console/*.cpp" "src/console/*.h")
add_library(CONSOLE_MDL src/console/console.cpp src/console/console.h)

file(GLOB SESSION_SRCS "src/session-manager/*.h" "src/session-manager/*.cpp")
add_library(SESSION_MDL ${SESSION_SRCS})

# Other
file(GLOB TEST_SRCS "test/*.cpp")

# Executables
add_executable(traffic_logger src/main.cpp)
add_executable(unit_tests ${TEST_SRCS} ${CONSOLE_SRCS} ${SESSION_SRCS})

# Linking external libs
target_link_libraries(unit_tests PUBLIC "${GTEST_LIB_FOLDER}/libgtestd.a")
target_link_libraries(traffic_logger console)
