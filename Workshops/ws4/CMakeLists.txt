cmake_minimum_required(VERSION 3.26)
project(DIY)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DIY
        Guitar.cpp
        Guitar.h
        main.cpp)
