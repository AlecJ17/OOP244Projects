cmake_minimum_required(VERSION 3.27)
project(ms3)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(ms3
        IOAble.cpp
        IOAble.h
        main.cpp
        Patient.cpp
        Patient.h
        Ticket.cpp
        Ticket.h
        Time.cpp
        Time.h
        Utils.cpp
        Utils.h)
