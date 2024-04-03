//
// Created by Admin on 03.04.2024.
//
#include "Double Linked List.h"
#include <iostream>

DLL::DLL() : size(0) {
    head = new Head();
    tail = new Tail();
}

DLL::DLL(DLL *to_copy) {
    head = new Head();
    tail = new Tail();
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

DLL:: ~DLL(){
    clear();
    delete head;
    delete tail;
}

int DLL::isEmpty() {
    if (head->getNext() == nullptr) {
        return 1;
    } else {
        return 0;
    }
}

int DLL::getSize() {return size;}

void DLL::clear() {
    INode* current = head->getNext();
    INode* next = nullptr;

    while (current != nullptr){
        next = current-> getNext();
        delete current;
        current = next;
    }
    head->setNext(nullptr);
    tail->setPrevious(nullptr);
    size = 0;
}

void DLL::init(int data) {
    insertBack(data);
}

void DLL::insertFront(int data) {
    if (size == 0) {
        INode* buf = new Node_extended(nullptr, nullptr, data);
        head->setNext(buf);
        tail->setPrevious(buf);
    } else {
        INode* next = head->getNext();
        INode* buf = new Node_extended(next, nullptr, data);
        next->setNext(next->getNext());
        next->setPrevious(buf);
        head->setNext(buf);
        if (next->getPrevious()) {
            tail->setPrevious(next->getPrevious());
        }
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
            INode* old = head->getNext();
            for(int i = 0;  i < index - 1; i++){
                old = old->getNext();
            }
            INode* buf = new Node_extended(old->getNext(),old, data);
            old->setNext(buf);
            size++;
            return 0;
        }else{
            //index in higher half, we go from tail
            INode* old = tail->getPrevious();
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

void DLL::insertBack(int data) {
    if (size == 0){
        insertFront(data);
    }else{
        INode* current = tail->getPrevious();
        INode* buf = new Node_extended(nullptr, current->getPrevious(), data);
        tail->setPrevious(buf);
        size++;
    }
}

std::optional<int> DLL::removeFront() {
    INode* current = head->getNext();

    if(current != nullptr){
        INode* next = current->getNext();
        int data = dynamic_cast<Node_extended*>(current)->getData();
        delete current;
        head->setNext(next);
        size --;
        return data;
    }else{
        return std::nullopt;
    }
}

std::optional<int> DLL::remove(int index) {
    if(index == 0){
        removeFront();
    }else if (index == size){
        removeBack();
    }
    if(index > 0 && index <size){
        if(index < size/2){
            INode* current = head->getNext();
            for (int i = 0; i < index -1; i++){
                current=current->getNext();
            }
            INode* next = current->getNext();
            int data = dynamic_cast<Node_extended*>(next)->getData();
            current->setNext(next->getNext());
            delete next;
            size--;
            return data;
        }else{
            INode* current = tail->getPrevious();
            for (int i = size - 1; i > index; i--){
                current=current->getPrevious();
            }
            INode* prev = current->getPrevious();
            int data = dynamic_cast<Node_extended*>(prev)->getData();
            current->setPrevious(prev->getPrevious());
            delete prev;
            size--;
            return data;
        }
    }else return std::nullopt;
}

std::optional<int> DLL::removeBack() {
    if (size == 0) return std::nullopt;
    return remove (size-1);
}

std::optional<int> DLL::get(int index) {
    // Lista
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    if(index >= 0 && index <= size) {
        // 9, 8, 7, 6, 5
        if (index < size / 2) {
            INode *buf = head->getNext();
            for (int i = 0; i < index; i++) {
                buf = buf->getNext();
            }
            return dynamic_cast<Node_extended *>(buf)->getData();
        // 4.
        } else {
            INode* buf = tail->getPrevious();
            for (int i = size; i > index; i--) {
                buf = buf->getPrevious();
            }
            return dynamic_cast<Node_extended *>(buf)->getData();
        }
    } else return std::nullopt;
}

int DLL::find(int data) {
    INode* current = head->getNext();// jesli head wskazuje na nullptr - brak elementów
    int i = 0;
    int found;
    while (i < size){
        found = dynamic_cast<Node_extended*>(current)->getData();
        if ( found == data) return i;
        else {
            i++;
            current = current->getNext();
        }
    }
    return -1;
}