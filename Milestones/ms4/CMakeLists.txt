cmake_minimum_required(VERSION 3.27)
project(ms4)

set(CMAKE_CXX_STANDARD 17)

add_executable(ms4 main.cpp
        TestPatient.h
        TestPatient.cpp
        Utils.h
        Utils.cpp
        TriagePatient.h
        TriagePatient.cpp
        Time.h
        Time.cpp
        Ticket.h
        Ticket.cpp
        IOAble.cpp
        Patient.cpp)
