cmake_minimum_required(VERSION 3.17.2)
project(advent_2020
    VERSION 0.1.0
    DESCRIPTION "Advent of code 2020"
    LANGUAGES CXX)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)



add_subdirectory(src)
add_subdirectory(test)