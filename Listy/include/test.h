//
// Created by grzegorz on 28.03.24.
//

#ifndef LISTY_TEST_H
#define LISTY_TEST_H
#include <ctime>

#include "List(head, tail).h"
#include "List(head).h"
#include "Double Linked List.h"
#include "Dynamic array.h"

long double test_insertFront(IDataStructure** sd, int data, int n);
long double test_insert(IDataStructure** sd, int data, int* index, int number_of_tests, int number_of_values);
long double test_insertBack(IDataStructure** sd, int data, int n);

long double test_removeFront(IDataStructure** sd, int n);
long double test_remove(IDataStructure** sd, int* index, int number_of_tests, int number_of_values);
long double test_removeBack(IDataStructure** sd, int n);

long double test_find(IDataStructure** sd, int* values, int number_of_tests, int number_of_values);

#endif //LISTY_TEST_H
