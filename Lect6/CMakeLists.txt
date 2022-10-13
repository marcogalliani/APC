cmake_minimum_required(VERSION 3.23)
project(Lect6)

set(CMAKE_CXX_STANDARD 11)

add_executable(use_of_this use_of_this/use_of_this.cpp use_of_this/X_fixed.cpp use_of_this/X.h)

add_executable(VectGetSet Matlab_vectors/MatlabVectorGetSet/MatlabVectorGetSet.cpp Matlab_vectors/MatlabVectorGetSet/MatlabVector.cpp Matlab_vectors/MatlabVectorGetSet/MatlabVector.h)

add_executable(VectOpInClass Matlab_vectors/MatlabVectorOperatorInClass/MatlabVectorOperatorInClass.cpp Matlab_vectors/MatlabVectorOperatorInClass/MatlabVector.h Matlab_vectors/MatlabVectorOperatorInClass/MatlabVector.cpp)

add_executable(VectRef Matlab_vectors/MatlabVectorReference/MatlabVectorReference.cpp Matlab_vectors/MatlabVectorReference/MatlabVector.h Matlab_vectors/MatlabVectorReference/MatlabVector.cpp)

add_executable(Date Date/testDates.cpp Date/Date.cpp Date/Date.h)

add_executable(returnRef returnRef/returnRef.cpp returnRef/BaseOK.h returnRef/BaseOK.cpp returnRef/BaseKO.h returnRef/BaseKO.cpp)

