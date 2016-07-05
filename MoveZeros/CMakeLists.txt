cmake_minimum_required(VERSION 3.5)
project(MoveZeros)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    MoveZeros.cpp)

add_executable(MoveZeros ${SOURCE_FILES})