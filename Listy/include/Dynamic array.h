//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_DYNAMIC_ARRAY_H
#define LISTY_DYNAMIC_ARRAY_H
#include <cstring>
#include "IDataStructure.h"
#include "iostream"
class DynamicArray: public IDataStructure{
private:
    int *array = nullptr;
    int size;
    int capacity;
public:
    DynamicArray();
    DynamicArray(DynamicArray *to_copy);
    int getSize() override;
    int isEmpty() override;

    int find(int value) override;
    std::optional<int> get(int index) override;
    void init(int data) override;

    void insertFront(int data) override;
    int insert(int data, int index) override;
    void insertBack(int data) override;

    std::optional<int>removeFront() override;
    std::optional<int> remove(int index) override;
    std::optional<int>removeBack()override;
    void grow();
    void shrink();
    ~DynamicArray() override;
};
#endif //LISTY_DYNAMIC_ARRAY_H
