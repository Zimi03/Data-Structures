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
        "include/Tail.h"
        "include/read_write.h"
        "include/IDataStructure.h"
        "include/Node_extended.h"
        src/main.cpp
        src/Node.cpp
        "src/List(head).cpp"
        src/Head.cpp
        "src/List(head, tail).cpp"
        src/Tail.cpp
        src/read_write.cpp

        src/Node_extended.cpp
        src/Dynamic_array.cpp
        src/test.cpp
        include/test.h
        src/test.cpp
)
