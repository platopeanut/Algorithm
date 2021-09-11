cmake_minimum_required(VERSION 3.20)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp list/List.h list/LinkedList.cpp list/LinkedList.h list/ArrayList.cpp list/ArrayList.h list/Node.h)
