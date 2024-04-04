//
// Created by grzegorz on 28.03.24.
//

#include "test.h"

/**
 * Function testing insertFront operation for data structure
 * @param sd - data structure
 * @param data
 * @param number_of_tests
 * @return time per one operation in [ms]
 */
long double test_insertFront(IDataStructure** sd, int data, int number_of_tests) {
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < number_of_tests; i++) {
        sd[i]->insertFront(data);
    }
    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((long double)time/CLOCKS_PER_SEC) / number_of_tests;
}

/**
 * Function testing insert operation for data structure
 * @param sd - data structure
 * @param data - to insert
 * @param index - array of index
 * @param number_of_tests
 * @param number_of_values
 * @return
 */
long double test_insert(IDataStructure** sd, int data, int* index, int number_of_tests, int number_of_values){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for(int j = 0; j < number_of_tests; j++){
        for (int i = 0; i < number_of_values; i++) {
            sd[i+j*number_of_values]->insert(index[i],data);
        }
    }
    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((double)time/CLOCKS_PER_SEC)/(number_of_tests*number_of_values);
}

/**
 * Function testing insertBack operation for data structure
 * @param sd - data structure
 * @param data - to insert
 * @param number_of_tests
 * @return
 */
long double test_insertBack(IDataStructure** sd, int data, int number_of_tests){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < number_of_tests; i++) {
        sd[i]->insertBack(data);
    }
    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((double)time/CLOCKS_PER_SEC) / number_of_tests;
}

/**
 * Function testing removeFront operation for data structure
 * @param sd - data structure
 * @param number_of_tests
 * @return
 */
long double test_removeFront(IDataStructure** sd, int number_of_tests){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < number_of_tests; i++) {
        sd[i]->removeFront();
    }
    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((double)time/CLOCKS_PER_SEC) / number_of_tests;
}

/**
 * Function testing remove operation for data structure
 * @param sd - data structure
 * @param index - array of index
 * @param number_of_tests
 * @param number_of_values
 * @return
 */
long double test_remove(IDataStructure** sd, int* index, int number_of_tests, int number_of_values){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for(int j = 0; j < number_of_tests; j++){
        for (int i = 0; i < number_of_values; i++) {
            sd[i+j*number_of_values]->remove(index[i]);
        }
    }
    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((double)time/CLOCKS_PER_SEC)/(number_of_tests*number_of_values);
}

/**
 * Function testing removeBack operation for data structure
 * @param sd - data structure
 * @param number_of_tests
 * @return
 */
long double test_removeBack(IDataStructure** sd, int number_of_tests){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for (int i = 0; i < number_of_tests; i++) {
        sd[i]->removeBack();
    }
    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((double)time/CLOCKS_PER_SEC) / number_of_tests;
}

/**
 * Function testing find operation for data structure
 * @param sd - data structure
 * @param values - array of values to find
 * @param number_of_tests
 * @param number_of_values
 * @return
 */
long double test_find(IDataStructure** sd, int* values, int number_of_tests, int number_of_values){
    if (number_of_tests <= 0) return -1; // checks if number of operations greater than 0

    long time_start = clock();
    for(int j = 0; j < number_of_tests; j++){
        for (int i = 0; i < number_of_values; i++) {
            sd[0]->find(values[i]);
        }
    }

    long time = 1000*(clock()-time_start); // wynik bedzie w ms

    return ((double)time/CLOCKS_PER_SEC)/(number_of_tests*number_of_values);
}


