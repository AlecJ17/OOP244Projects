cmake_minimum_required(VERSION 3.27)
project(ms5)

set(CMAKE_CXX_STANDARD 14)

add_executable(ms5
#        main.cpp
        Utils.cpp
        Utils.h
        PreTriage.cpp
        PreTriage.h
        IOAble.cpp
        IOAble.h
        Patient.cpp
        Patient.h
        Ticket.cpp
        Ticket.h
        Time.cpp
        Time.h
        TriagePatient.cpp
        TriagePatient.h
#        ms51_test.cpp
        TestPatient.cpp
        Menu.cpp
        Menu.h
        smalldata.csv
#        ms52_test.cpp
#        ms53_test.cpp
#        ms54_test.cpp
        ms56_test.cpp)