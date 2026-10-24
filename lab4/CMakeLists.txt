cmake_minimum_required(VERSION 4.3)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 main.cpp
        example1/Animal.cpp
        example1/Animal.h
        example1/Pet.cpp
        example1/Pet.h
        example1/Dog.cpp
        example1/Dog.h
        example2/Account.cpp
        example2/Account.h
        example2/SavingAccount.cpp
        example2/SavingAccount.h
        example2/CreditAccount.cpp
        example2/CreditAccount.h
        example3/Shape.h
        example3/Circle.h
        example3/Rectangle.h
        example3/RightTriangle.h)
