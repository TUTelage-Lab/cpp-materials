cmake_minimum_required(VERSION 4.3)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 main.cpp
        example1/Triangle.cpp
        example1/Triangle.h
        exercise1/Time.cpp
        exercise1/Time.h
        exercise2/Worker.cpp
        exercise2/Worker.h
        exercise3/Line.cpp
        exercise3/Line.h
)
