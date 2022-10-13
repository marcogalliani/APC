cmake_minimum_required(VERSION 3.23)
project(Lect1)

set(CMAKE_CXX_STANDARD 11)


add_executable(fibonacci fibonacci.c)
add_executable(hello_dan hello_dan.cpp)
add_executable(hello_world hello_world.cpp)
add_executable(myfirstclass myfirstclass.cpp X.cpp X.h)
add_executable(namespace namespace.cpp MyFriendLibrary.cpp MyFriendLibrary.h)
add_executable(opplus opplus.cpp)
add_executable(typesafe typesafe.cpp)
add_executable(unsigned unsigned.cpp)
add_executable(vect vect.cpp)
add_executable(wrapping wrapping.cpp)
add_executable(ifex ifex.cpp)