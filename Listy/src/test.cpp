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


long double test_insert(IDataStructure** sd, int data, int* index, int n){
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->insert(index[i], data);
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/n;
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

long double test_remove(IDataStructure** sd, int* index, int n){
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->remove(index[i]);
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/n;
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

long double test_find(IDataStructure** sd, int* values, int n){
    if (n <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < n; i++) {
        sd[i]->find(values[i]);
    }
    long time = clock()-time_start;

    return ((double)time/CLOCKS_PER_SEC)/n;
}


