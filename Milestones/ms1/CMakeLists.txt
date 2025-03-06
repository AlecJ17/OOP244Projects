cmake_minimum_required(VERSION 3.27)
project(ms1)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(ms1
        main.cpp
        Menu.cpp
        Menu.h
        Time.cpp
        Time.h
        Utils.cpp
        Utils.h)
