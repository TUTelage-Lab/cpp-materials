cmake_minimum_required(VERSION 4.3)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp
        example1/BankAccount.cpp
        example1/BankAccount.h
        example2/Loan.cpp
        example2/Loan.h
        example3/Sensor.cpp
        example3/Sensor.h
        exercise1/Student.cpp
        exercise1/Student.h
        exercise2/Student.cpp
        exercise2/Student.h
        exercise2/Course.cpp
        exercise2/Course.h
)
