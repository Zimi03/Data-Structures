cmake_minimum_required(VERSION 3.27)
project(Listy)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(Listy
        "include/DoubleLinkedList.h"
        "include/Dynamic array.h"
        "include/Head.h"
        "include/IDataStructure.h"
        "include/INode.h"
        "include/List(head, tail).h"
        "include/List(head).h"
        "include/Node_extended.h"
        "include/Node.h"
        "include/read_write.h"
        "include/Tail.h"
        "include/test.h"

        "src/DoubleLinkedList.cpp"
        "src/Dynamic_array.cpp"
        "src/Head.cpp"
        "src/List(head, tail).cpp"
        "src/List(head).cpp"
        "src/main.cpp"
        "src/Node_extended.cpp"
        "src/Node.cpp"
        "src/read_write.cpp"
        "src/Tail.cpp"
        "src/test.cpp"
)
