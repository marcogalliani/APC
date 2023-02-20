cmake_minimum_required(VERSION 3.23)
project(counter_queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(counter_queue main.cpp
        counter_queue_initial.h
        counter_queue_initial.cpp)
