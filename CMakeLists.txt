cmake_minimum_required(VERSION 3.24)
project(Review_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Review_Project
        gradebook.cpp
        gradebook.h
        Main.cpp)
