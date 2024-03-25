//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_LIST_HEAD_H
#define LISTY_LIST_HEAD_H
#include "IDataStructure.h"
#include "Node.h"
#include "Head.h"


class List_h : public IDataStructure{
protected:
    int size;
    Head *head;
public:
    List_h();
    ~List_h() override;
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
#endif //LISTY_LIST_HEAD_H
