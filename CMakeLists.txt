cmake_minimum_required(VERSION 3.12)
project(Apollo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Apollo
        main.cpp
        header/cvconfig.h
        header/cvdef.h
        header/test.h
        header/interface.h)