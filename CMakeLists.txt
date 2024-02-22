cmake_minimum_required(VERSION 3.27)
project(PhotoBatch)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        PhotoBatch
        PhotoBatch.cpp
        ArgumentParser.cpp
        ArgumentParser.h
        Utils.h
        Utils.cpp)
