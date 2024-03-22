//
// Created by grzegorz on 22.03.24.
//

#ifndef LISTY_HEAD_H
#define LISTY_HEAD_H
#include "INode.h"

class Head: public INode{
private:
    INode* next;
public:
    Head();
    INode* getNext() override;
    void setNext(INode* next) override;


};


#endif //LISTY_HEAD_H
