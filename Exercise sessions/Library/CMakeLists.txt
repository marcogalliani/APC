cmake_minimum_required(VERSION 3.23)
project(Library)

set(CMAKE_CXX_STANDARD 11)

add_executable(Library main.cpp Book.cpp Book.h Library.cpp Library.h)
