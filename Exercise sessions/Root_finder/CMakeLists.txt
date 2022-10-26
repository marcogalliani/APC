cmake_minimum_required(VERSION 3.15)
project(RootFinderAllInOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(RootFinderAllInOne bn_allinone.cpp)
add_executable(ClassRestructured restructured_main.cpp Function.cpp Function.h restructured_main.cpp Bisection.cpp Bisection.h  RootFinder.cpp RootFinder.h Newton.cpp Newton.h Robust.cpp Robust.h)
