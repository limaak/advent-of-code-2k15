# setup
cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic-errors -Werror")

# project
project(aoc2015)

# execs
add_executable(day01 src/day01.cpp)
