//
// Created by grzegorz on 22.03.24.
//

#ifndef LISTY_NODE_H
#define LISTY_NODE_H
#include "INode.h"

class Node: public INode{
private:
    int data;
    INode* next;

public:
    explicit Node(INode* _next, int _data);
    INode* getNext() override;
    int setNext(INode* _next) override;
    INode* getPrevious() override;
    int setPrevious(INode* _previous) override;
    int getData();
};


#endif //LISTY_NODE_H
