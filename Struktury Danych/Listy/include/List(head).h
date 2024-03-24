//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_LIST_HEAD_H
#define LISTY_LIST_HEAD_H
#include "Node.h"
#include "Head.h"
#include <optional>

class List_h {
private:
    int size;
    INode *head;
public:
    List_h();
    ~List_h();
    int isEmpty();
    int getSize();
    void clear();

    void insertFront(int data);
    int insert(int index, int data);
    void insertBack(int data);
    std::optional<int> removeFront();
    std::optional<int> remove(int index);
    std::optional<int> removeBack();

    std::optional<int> get(int index);
    int find(int data);


};
#endif //LISTY_LIST_HEAD_H
