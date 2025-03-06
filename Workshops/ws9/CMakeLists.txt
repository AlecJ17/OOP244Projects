cmake_minimum_required(VERSION 3.27)
project(WS09)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS09 main.cpp
        Book.cpp
        LibraryItem.h
        LibraryItem.cpp)
