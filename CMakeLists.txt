cmake_minimum_required(VERSION 3.27)
project(PhotoBatch)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhotoBatch main.cpp
        ArgumentParser.cpp
        ArgumentParser.h)
