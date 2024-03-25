//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_LIST_HEAD_TAIL_H
#define LISTY_LIST_HEAD_TAIL_H
#include "Tail.h"
#include "List(head).h"
class List_h_t:  public List_h{ // a może dziedziczenie z klasy LIST(HEAD)
private:
    Tail *tail;

public:
    List_h_t();
    ~List_h_t() override;

    void clear();

    void insertFront(int data) override;
    int insert(int index, int data) override;
    void insertBack(int data) override;

    std::optional<int> removeFront() override;
    std::optional<int> remove(int index) override;

    std::optional<int> get(int index) override;

};
#endif //LISTY_LIST_HEAD_TAIL_H
