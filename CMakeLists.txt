cmake_minimum_required(VERSION 3.12)
project(Apollo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Apollo
        main.cpp
        header/cvconfig.h
        header/cvdef.h
        header/test.h
        header/interface.h
        header/cv_cpu_dispatch.h
        header/cv_cpu_config.h
        header/cv_cpu_helper.h
        header/fast_math.hpp
        header/mat.hpp
        header/types.hpp)