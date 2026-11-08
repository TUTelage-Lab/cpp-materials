cmake_minimum_required(VERSION 4.3)
project(lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5 main.cpp
        example1/Vector2D.cpp
        example1/Vector2D.h
        example2/Fraction.cpp
        example2/Fraction.h
        example3/Matrix.h
        example3/Matrix.cpp
        example4/Polynomial.cpp
        example4/Polynomial.h
        exercise1/Complex.h
        exercise1/Complex.cpp
        exercise2/ConfigMap.h
        exercise2/ConfigMap.cpp
        exercise2/CircularBuffer.h
        exercise2/CircularBuffer.cpp
        exercise3/DynArray.h
        exercise3/DynArray.cpp)
