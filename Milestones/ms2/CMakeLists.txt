cmake_minimum_required(VERSION 3.26)
project(ms2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ms2
        IOAble.cpp
        IOAble.h
        main.cpp)
