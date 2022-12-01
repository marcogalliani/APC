cmake_minimum_required(VERSION 3.23)
project(Lect12)

set(CMAKE_CXX_STANDARD 11)

add_executable(BoxesV1 BoxesV1/BoxV1_main.cpp BoxesV1/Box.cpp BoxesV1/Box.h)

add_executable(BoxesV2 BoxesV2/BoxV2_main.cpp BoxesV2/Box.cpp BoxesV2/Box.h)

add_executable(CopyControl CopyControl/CpyControl_main.cpp CopyControl/MyClass.cpp CopyControl/MyClass.h )