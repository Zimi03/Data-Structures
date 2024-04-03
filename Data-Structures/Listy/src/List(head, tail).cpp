//
// Created by grzegorz on 25.03.24.
//

#include "List(head, tail).h"

List_h_t::List_h_t(): List_h(){
    tail = new Tail;
}

List_h_t::List_h_t(List_h_t *to_copy) {
    head = new Head();
    tail = new Tail;
    std::optional<int> value;
    int _size = to_copy->getSize();

    if (_size != 0) {
        for (int i = 0; i < _size; i++) {
            value = to_copy->get(i);
            if(value!=std::nullopt){
                insertBack(value.value());
            }
        }
    }
}

List_h_t::~List_h_t() {
    clear();
    delete tail;
}

/**
 * Removes all elements of the list except for the head and tail element, which points to nullptr.
 */
void List_h_t::clear() {
    INode* current = head->getNext(); // jesli head wskazuje na nullptr - brak elementów
    INode* next = nullptr;

    while (current != nullptr){
        next = current->getNext();
        delete current;
        current = next;
    }

    head->setNext(nullptr);
    tail->setPrevious(nullptr);
    size = 0;
}

/**
 * Init list(head, tail) with insertBack - it is necessary for fast initzialization of data structure
 */
void List_h_t::init(int data){
    insertBack(data);
}

/**
 * Inserts element on front
 * @param data
 */
void List_h_t::insertFront(int data) {

    INode* buf = new Node(head->getNext(), data);
    head->setNext(buf);
    if (size == 0){
    tail->setPrevious(buf);
    }
    size++;
}

/**
 * Inserts element on given index if possible
 * @param data
 * @param index
 * @return 0 - success
 * @return 1 - fail
 */
int List_h_t::insert(int index, int data) {
    if(index == 0) {
        insertFront(data);
        return 0;
    } else if (index == size) {
        insertBack(data);
        return 0;
    }

    if(index > 0 && index <= size){
        INode* old = head->getNext();
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

/**
 * Inserts element to the end of list
 * @param data
 */
void List_h_t::insertBack(int data) {
    if(size == 0) {
        insertFront(data);
    } else {
        INode* current = tail->getPrevious();
        INode* buf = new Node(nullptr, data);
        current->setNext(buf);
        tail->setPrevious(buf);
        size++;
    }

}

/**
 * Removes first element from list
 * @return data from removed element
 * @return std::nullopt - if empty
 */
std::optional<int> List_h_t::removeFront() {
    INode* current = head->getNext(); // jesli head wskazuje na nullptr - brak elementów

    if(current != nullptr)
    {
        INode* next = current->getNext();
        int data = dynamic_cast<Node*>(current)->getData();
        delete current;
        head->setNext(next);
        if(size==1){
            tail->setPrevious(next);
        }
        size--;
        return data;
    } else {
        return std::nullopt; // Lista jest pusta, nie ma czego zwrócić.
    }
}

/**
 * Removes element from the given index from list
 * @return data from removed element - if index ok
 * @return std::nullopt - if wrong index
 */
std::optional<int> List_h_t::remove(int index) {
    if(index >= size || index < 0 ) return std::nullopt;
    if(index == 0) return removeFront();

    INode* current = head->getNext();// jesli head wskazuje na nullptr - brak elementów

    for(int i = 0; i < index - 1 ; i++){ // musimy dotrzeć do node o indeksie "index-1"
        current = current->getNext();
    }
    INode* next = current->getNext();
    int data = dynamic_cast<Node*>(next)->getData();
    current->setNext(next->getNext());
    if(index == size - 1) {
        tail->setPrevious(current);
    }
    delete next;
    size--;
    return data;
}

/**
 * Returns data on given index
 * @param index
 * @return data - if index ok
 * @return std::nullopt - if index wrong
 */
std::optional<int> List_h_t::get(int index) {
    if(index == size - 1 && index >= 0){
        INode* buf = tail->getPrevious();
        return dynamic_cast<Node*>(buf)->getData();
    }

    INode* buf = head->getNext();
    if(index >= 0 && index < size){
        for(int i = 0; i < index; i++){
            buf = buf->getNext();
        }
        return dynamic_cast<Node*>(buf)->getData();
    } else {
        return std::nullopt;
    }
}