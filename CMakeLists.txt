cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled src/main.cpp
        src/Menu.cpp
        src/Menu.h
        src/Student.cpp
        src/Student.h
        src/Slot.cpp
        src/Slot.h
        src/Schedule.h
        src/Schedule.cpp
        src/ClassAndUc.cpp
        src/ClassandUc.h
        src/Data.cpp
        src/Data.h)