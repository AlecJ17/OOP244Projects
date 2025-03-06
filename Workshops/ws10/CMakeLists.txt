cmake_minimum_required(VERSION 3.27)
project(WS10)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS10 main.cpp
        Book.cpp
        Student.h
        Student.cpp
)
