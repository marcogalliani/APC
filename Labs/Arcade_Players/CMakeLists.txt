cmake_minimum_required(VERSION 3.23)
project(Lab4)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lab4 main.cc
        Player.cc
        Player.hh
        RandomPlayerGenerator.cc
        RandomPlayerGenerator.hh
        search.cc
        search.hh
        timing.cc
        timing.hh)
