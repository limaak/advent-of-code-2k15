# setup
cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic-errors")

# project
project(aoc2015)

find_package(Boost)
find_package(poco)

add_subdirectory(third_party)
include_directories(third_party)

# execs
add_executable(day01 src/day01.cpp)
add_executable(day02 src/day02.cpp)
add_executable(day02_short src/day02_short.cpp)
add_executable(day03 src/day03.cpp)
add_executable(day04 src/day04.cpp)
add_executable(day05 src/day05.cpp)
add_executable(day05_regex src/day05_regex.cpp)

# links
target_link_libraries(day04 PUBLIC md5_lib)
