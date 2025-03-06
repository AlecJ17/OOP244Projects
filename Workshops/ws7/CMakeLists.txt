cmake_minimum_required(VERSION 3.27)
project(WS07)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS07 main.cpp
        DepositUtility.h
        DepositUtility.cpp
        BankAccount.cpp
        SavingsAccount.cpp)
