cmake_minimum_required(VERSION 4.3)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 main.cpp
        example1/BankAccount.h
        example1/BankAccount.cpp
        example2/Account.h
        example2/Account.cpp
        example2/SavingsAccount.h
        example2/SavingsAccount.cpp
        example2/CreditAccount.h
        example2/CreditAccount.cpp
        example3/Shape.h
        example3/Shape.cpp
        example3/Circle.h
        example3/Rectangle.h
        example3/Triangle.h
        example3/RightTriangle.h
        example4/Employee.h
        example4/Employee.cpp
        example4/HourlyEmployee.h
        example4/HourlyEmployee.cpp
        example4/SalariedEmployee.h
        example4/SalariedEmployee.cpp
        example4/CommissionEmployee.h
        example4/CommissionEmployee.cpp
        exercise1/Device.h
        exercise1/Device.cpp
        exercise1/NetworkDevice.h
        exercise1/NetworkDevice.cpp
        exercise1/StorageDevice.h
        exercise1/StorageDevice.cpp
        exercise1/NAS.h
        exercise1/NAS.cpp
        exercise2/Vehicle.h
        exercise2/Vehicle.cpp
        exercise2/Truck.h
        exercise2/Truck.cpp
        exercise2/Bus.h
        exercise2/Bus.cpp)
