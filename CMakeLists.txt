cmake_minimum_required(VERSION 3.20)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp src/list/List.h src/list/ArrayList.h src/list/ArrayList.cpp)
