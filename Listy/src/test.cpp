//
// Created by grzegorz on 28.03.24.
//

#include "test.h"

long double test_insertFront(IDataStructure** sd, int data, int n) {
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->insertFront(data);
    }
    long time = clock()-time_start;

    return ((long double)time/CLOCKS_PER_SEC)/n;
}


long double test_insert(IDataStructure** sd, int data, int* index, int number_of_tests, int number_of_values){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
//    for (int i = 0; i < n; i++) {
//        sd[i]->insert(index[i], data);
//    }
    for(int j = 0; j < number_of_tests; j++){
        for (int i = 0; i < number_of_values; i++) {
            sd[i+j*number_of_values]->insert(index[i],data);
        }
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/(number_of_tests*number_of_values);
}


long double test_insertBack(IDataStructure** sd, int data, int n){
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->insertBack(data);
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/n;
}


long double test_removeFront(IDataStructure** sd, int n){
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->removeFront();
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/n;
}

long double test_remove(IDataStructure** sd, int* index, int number_of_tests, int number_of_values){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
//    for (int i = 0; i < n; i++) {
//        sd[i]->remove(index[i]);
//    }

    for(int j = 0; j < number_of_tests; j++){
        for (int i = 0; i < number_of_values; i++) {
            sd[i+j*number_of_values]->remove(index[i]);
        }
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/(number_of_tests*number_of_values);
}

long double test_removeBack(IDataStructure** sd, int n){
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->removeBack();
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/n;
}

long double test_find(IDataStructure** sd, int* values, int number_of_tests, int number_of_values){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for(int j = 0; j < number_of_tests; j++){
        for (int i = 0; i < number_of_values; i++) {
            sd[0]->find(values[i]);
        }
    }

    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/(number_of_tests*number_of_values);
}


