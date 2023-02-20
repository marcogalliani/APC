cmake_minimum_required(VERSION 3.23)
project(DataFrameChallenge2_BASE)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataFrameChallenge2_BASE main.cpp
        Column.h
        Column.cpp
        DataFrame.h
        DataFrame.cpp
        checkChallenge.h
        checkChallenge.cpp)
