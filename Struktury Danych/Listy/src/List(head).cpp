//
// Created by grzegorz on 22.03.24.
//

#include "List(head).h"

List_h::List_h() : size(0) {
    head = new Head();
}

/**
 * Function chcecks if list is empty
 * @return 0 - not empty
 * @return 1 - empty
 */
int List_h::isEmpty() {
    if(size == 0) {
        return 1;
    } else return 0;
}

/**
 * Returns size of list
 * @return size
 */
int List_h::getSize() {
    return size;
}

/**
 * Returns data on given index
 * @param index
 * @return
 */
int List_h::get(int index) {
    INode* buf = head;
    if(index >= 0 && index < size){
        for(int i = 0; i < index; i++){
            buf = buf->getNext();
        }
        return dynamic_cast<Node*>(buf)->getData();
    }
    // a co jeśli index'u nie ma w liście?
}

/**
 * Inserts data on front
 * @param data
 */
void List_h::insertFront(int data) {
    INode* buf = new Node(head, data);
    head = buf;
    size++;
}

/**
 * Inserts data on given index if possible
 * @param data
 * @param index
 * @return 0 - success
 * @return 1 - fail
 */
int List_h::insert(int index, int data) {
    if(index == 0) {
        insertFront(data);
        return 0;
    }

    if(index > 0 && index < size){
        INode* old = head;
        for(int i = 0; i < index - 1 ; i++){ // musimy dotrzeć do node o indeksie "index-1"
            old = old->getNext();
        }
        INode* buf = new Node(old->getNext(), data);
        old->setNext(buf);
        size++;
        return 0;
    }
    return 1;
}

void List_h::insertBack(int data) {
    if(size == 0) {
        insertFront(data);
    } else {
        INode* old = head;
        for(int i = 0; i < size - 1 ; i++){ // musimy dotrzeć do ostatniego elementu
            old = old->getNext();
        }
        INode* buf = new Node(nullptr, data);
        old->setNext(buf);
        size++;
    }

}