#include "Double Linked List.h"
#include <iostream>
#include <stdexcept>

DLL::DLL() : size(0) {
    // Next -> from HEAD to TAIL (aka HEAD)
    // Prev -> from TAIL to HEAD (2head meme) (aka TAIL)
    referenceNode = new Node_extended(nullptr, nullptr, NULL);
}

DLL::DLL(DLL *to_copy) {
    referenceNode = new Node_extended(nullptr, nullptr, NULL);
    std::optional<int> value;
    int _size = to_copy->getSize();

    if (_size != 0){
        for(int i = 0; i < _size; i++){
            value = to_copy->get(i);
            if (value != std::nullopt){
                insertBack(value.value());
            }
        }
    }
}

DLL:: ~DLL() {
    clear();
    delete referenceNode;
}

int DLL::isEmpty() {
    return referenceNode->getNext() == nullptr ? 1 : 0;
}

int DLL::getSize() {
    return size;
}

void DLL::clear() {
    INode* current = referenceNode->getNext();
    INode* next = nullptr;

    while (current != nullptr) {
        next = current->getNext();
        delete current;
        current = next;
    }

    referenceNode->setNext(nullptr);
    referenceNode->setPrevious(nullptr);
    size = 0;
}

void DLL::init(int data) {
    // Because yes
    insertBack(data);
}

void DLL::insertBack(int data) {
    if (size == 0) {
        insertFront(data);
        return;
    }

    INode* buf = new Node_extended(nullptr, referenceNode->getPrevious(), data);
    referenceNode->setPrevious(buf);
    size++;
}

void DLL::insertFront(int data) {
    if (size == 0) {
        INode* buf = new Node_extended(nullptr, nullptr, data);
        referenceNode->setPrevious(buf);
        referenceNode->setNext(buf);
    } else {
        INode* next = referenceNode->getNext();
        INode* buf = new Node_extended(next, nullptr, data);

        if (next) {
            next->setPrevious(buf);
        }

        referenceNode->setNext(buf);
    }
    size++;
}

int DLL::insert(int index, int data) {
    if (index == 0){
        insertFront(data);
        return 0;
    }else if (index == size){
        insertBack(data);
        return 0;
    }

    if(index > 0 && index < size){
        if (index < (size/2)){
            //index in lower half, we go from head
            INode* old = referenceNode->getNext();
            for(int i = 0;  i < index - 1; i++){
                old = old->getNext();
            }
            INode* buf = new Node_extended(old->getNext(),old, data);
            old->setNext(buf);
            size++;
            return 0;
        }else{
            //index in higher half, we go from referenceNode
            INode* old = referenceNode->getPrevious();
            for(int i = size-1; i > index; i--){
                old->getPrevious();
            }
            INode* buf = new Node_extended(old,old->getPrevious(), data);
            old->setPrevious(buf);
            size++;
            return 0;
        }
    }
    return 1;
}

std::optional<int> DLL::remove(int index) {
    std::optional<Node_extended*> node = DLL::getByIndex(index);
    if (!node.has_value()) return std::nullopt;

    INode* previous = node.value()->getPrevious();
    INode* next = node.value()->getNext();
    int value = node.value()->getData();

    if (!referenceNode->getNext()) {
        std::cout << "Missing getNext" << std::endl;
    }

    if (!referenceNode->getPrevious()) {
        std::cout << "Missing getPrevious" << std::endl;
    }

    if (previous) previous->setNext(next);
    if (next) next->setPrevious(previous);
    delete node.value();


    size--;
    return value;
}

std::optional<int> DLL::removeFront() {
    return remove(0);
}

std::optional<int> DLL::removeBack() {
    return remove(size-1);
}

int DLL::find(int data) {
    INode* current = referenceNode->getNext();
    int i = 0;
    int found;
    while (i < size){
        found = dynamic_cast<Node_extended*>(current)->getData();
        if (found == data) {
            return i;
        } else {
            i++;
            if (current->getNext()) {
                current = current->getNext();
            }
        }
    }
    return -1;
}

std::optional<int> DLL::get(int index) {
    std::optional<Node_extended*> node = DLL::getByIndex(index);
    if (!node.has_value()) return std::nullopt;
    return node.value()->getData();
}

std::optional<Node_extended*> DLL::getByIndex(int index) {
    if (index < 0 || index >= size) {
        return std::nullopt;
    }

    if (index < size / 2) {
        INode *buf = referenceNode->getNext();
        for (int i = 0; i < index; i++) {
            buf = buf->getNext();
        }
        return std::optional(dynamic_cast<Node_extended*>(buf));
    } else {
        INode* buf = referenceNode->getPrevious();
        for (int i = size - 1; i > index; i--) {
            buf = buf->getPrevious();
        }
        return std::optional(dynamic_cast<Node_extended*>(buf));
    }
}