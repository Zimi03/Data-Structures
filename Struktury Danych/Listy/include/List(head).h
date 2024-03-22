//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_LIST_HEAD_H
#define LISTY_LIST_HEAD_H
#include "Node.h"
#include "Head.h"


class List_h {
private:
    int size;
    INode *head;
public:
    List_h();
    int isEmpty();
    int getSize();

    void insertFront(int data);
    int insert(int index, int data);
    void insertBack(int data);
    int removeFront();
    int remove(int index);
    int removeBack();

    int get(int index);
    int find(int data);


};
#endif //LISTY_LIST_HEAD_H
