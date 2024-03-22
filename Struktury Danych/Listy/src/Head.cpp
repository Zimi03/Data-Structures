//
// Created by grzegorz on 22.03.24.
//

#include "Head.h"

Head::Head() {next = nullptr;}
INode* Head::getNext() { return next;}
void Head::setNext(INode* _next) {
    next = _next;
}