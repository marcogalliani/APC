cmake_minimum_required(VERSION 3.23)
project(KMeans_initial)

set(CMAKE_CXX_STANDARD 11)

add_executable(KMeans KMeans.cpp Centroid.cpp Centroid.h Clustering.cpp Clustering.h Point.cpp Point.h)