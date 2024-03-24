cmake_minimum_required(VERSION 3.27)
project(Listy)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(Listy
        "include/Double Linked List.h"
        "include/Dynamic array.h"
        "include/List(head).h"
        "include/List(head, tail).h"
        "include/Node.h"
        "include/Head.h"
        "include/INode.h"
        src/main.cpp
        src/Node.cpp
        "src/List(head).cpp"
        src/Head.cpp)
