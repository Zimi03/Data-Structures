//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_DOUBLE_LINKED_LIST_H
#define LISTY_DOUBLE_LINKED_LIST_H
#include "IDataStructure.h"
#include "Head.h"
#include "Tail.h"
#include "Node_extended.h"

class DLL: public IDataStructure{
private:
    int size;
    INode *head;
    INode *tail;
public:
    DLL();
    ~DLL() override;
    int isEmpty();
    int getSize();
    void clear();

    void insertFront(int data) override;
    int insert(int index, int data) override;
    void insertBack(int data) override;

    std::optional<int> removeFront() override;
    std::optional<int> remove(int index) override;
    std::optional<int> removeBack() override;

    std::optional<int> get(int index) override;
    int find(int data) override;

};

#endif //LISTY_DOUBLE_LINKED_LIST_H
