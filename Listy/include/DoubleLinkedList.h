//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_DOUBLE_LINKED_LIST_H
#define LISTY_DOUBLE_LINKED_LIST_H

#include "IDataStructure.h"
#include "Node_extended.h"

class DoubleLinkedList: public IDataStructure {
private:
    int size;
    INode *referenceNode;
public:
    DoubleLinkedList();
    DoubleLinkedList(DoubleLinkedList *to_copy);
    ~DoubleLinkedList() override;
    int isEmpty() override;
    int getSize() override;
    void clear();
    void init(int data) override;

    void insertFront(int data) override;
    int insert(int index, int data) override;
    void insertBack(int data) override;

    std::optional<int> remove(int index) override;
    std::optional<int> removeFront() override;
    std::optional<int> removeBack() override;

    std::optional<int> get(int index) override;
    std::optional<Node_extended*> getByIndex(int index);
    int find(int data) override;
};

#endif //LISTY_DOUBLE_LINKED_LIST_H
