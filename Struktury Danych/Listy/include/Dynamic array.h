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
    DynamicArray();
    DynamicArray(int capacity);
    int get_size();
    int get_capcity();
    int find(int value);
    void insert_at_given(int value, int index);
    void insert_at_end(int value);
    void delete_at_given(int index);
    void delete_at_end();
    void grow();
    void shrink();
    ~DynamicArray();
};
#endif //LISTY_DYNAMIC_ARRAY_H
