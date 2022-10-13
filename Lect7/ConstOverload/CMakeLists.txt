cmake_minimum_required(VERSION 3.23)
project(ConstOverload)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConstOverload main.cpp C.cpp C.h)
