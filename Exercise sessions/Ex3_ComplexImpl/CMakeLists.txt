cmake_minimum_required(VERSION 3.23)
project(ComplexImpl)

set(CMAKE_CXX_STANDARD 11)

add_executable(compl_main LectImpl/compl_main.cpp LectImpl/Complex.cpp LectImpl/Complex.h)

add_executable(compl_main_mod AltImpl/compl_main_mod.cpp AltImpl/Complex_mod.cpp AltImpl/Complex_mod.h)