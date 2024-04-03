//
// Created by grzegorz on 22.03.24.
//

#include "Node.h"

Node::Node(INode *_next, int _data) :  data(_data) {
    next = _next;
}


INode* Node::getNext() {return next;}


int Node::setNext(INode* _next) {
    next = _next;
    return 0;
}

INode* Node::getPrevious() {
    return nullptr;
}

int Node::setPrevious(INode* _previous) {
    return 1;
}

int Node::getData() {return data;}