//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_LIST_HEAD_TAIL_H
#define LISTY_LIST_HEAD_TAIL_H
#include "Tail.h"
#include "List(head).h"
class List_h_t: public List_h{ // a może dziedziczenie z klasy LIST(HEAD)
private:
    INode *tail;

public:
    List_h_t();
    ~List_h_t();

    void clear();

    void insertFront(int data);
    int insert(int index, int data);
    void insertBack(int data);

    std::optional<int> removeFront();
    std::optional<int> remove(int index);

    std::optional<int> get(int index);

};
#endif //LISTY_LIST_HEAD_TAIL_H
