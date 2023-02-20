cmake_minimum_required(VERSION 3.16)
project(Employee)

set(CMAKE_CXX_STANDARD 14)

add_executable(Employee main.cpp
        Employee.hh
        Manager.hh
        Manager.cpp
        Secretary.cpp
        Secretary.hh
        Developer.hh
        Developer.cpp)
