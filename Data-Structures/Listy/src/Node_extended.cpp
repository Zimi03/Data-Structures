//
// Created by grzegorz on 25.03.24.
//
#include "Node_extended.h"

Node_extended::Node_extended(INode *_next, INode *_prev, int _data) : data(_data) {
    next = _next;
    prev = _prev;
}

INode* Node_extended ::getNext() {
    return next;
}

int Node_extended::setNext(INode *_next) {
    next = _next;
    return 0;
}

INode* Node_extended ::getPrevious() {
    return prev;
}

int Node_extended::setPrevious(INode *_previous) {
    prev = _previous;
    return 0;
}

int Node_extended::getData() const {
    return data;
}