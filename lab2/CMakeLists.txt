cmake_minimum_required(VERSION 4.3)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp
        example1/BankAccount.cpp
        example1/BankAccount.h
        example2/Logger.cpp
        example2/Logger.h
        example3/Loan.cpp
        example3/Loan.h
        example4/Audit.cpp
        example4/Audit.h
        example4/Warehause.cpp
        example4/Warehouse.h)
