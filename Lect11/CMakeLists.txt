cmake_minimum_required(VERSION 3.23)
project(Lect11)

set(CMAKE_CXX_STANDARD 11)



add_executable(SharedPtr_Count_Shared_ptr_main SharedPtr_Count/Shared_ptr_main.cpp)
add_executable(StrLPVector_StrLPVector_main StrLPVector/StrLPVector_main.cpp StrLPVector/StrLPVector.h StrLPVector/StrLPVector.cpp)