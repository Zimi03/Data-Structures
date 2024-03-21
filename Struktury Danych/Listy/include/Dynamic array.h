//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_DYNAMIC_ARRAY_H
#define LISTY_DYNAMIC_ARRAY_H

#include <cstring>

class DynamicArray{
private:
    int *array = nullptr;
    int size;
    int capacity;
public:
     void insert_at_begin();
    void insert_at_given();
    void insert_at_end();
    void delete_at_begin();
    void delete_at_given();
    void delete_at_end();

};
#endif //LISTY_DYNAMIC_ARRAY_H
