//
// Created by grzegorz on 25.03.24.
//

#ifndef LISTY_NODE_EXTENDED_H
#define LISTY_NODE_EXTENDED_H

#include "INode.h"
#include "optional"

class Node_extended : public INode {
private:
    std::optional<int> data;
    INode* next;
    INode* prev;

public:
    explicit Node_extended(INode* _next, INode* _prev, std::optional<int> _data);
    INode* getNext() override;
    int setNext(INode* _next) override;
    INode* getPrevious() override;
    int setPrevious(INode* _previous) override;
    int getData() const;
};


#endif //LISTY_NODE_EXTENDED_H
