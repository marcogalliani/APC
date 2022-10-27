cmake_minimum_required(VERSION 3.23)
project(Gradient_descent)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gradient_descent main.cpp Function.cpp Function.h FunctionMin.cpp FunctionMin.h Monomials.cpp Monomials.h Point.cpp Point.h)
