//
// Created by grzegorz on 22.03.24.
//

#include "List(head).h"

List_h::List_h() : size(0) {
    head = new Head();
}

List_h::~List_h() {
    clear();
    delete head;
}

/**
 * Function chcecks if list is empty
 * @return 0 - not empty
 * @return 1 - empty
 */
int List_h::isEmpty() {
    if(head->getNext() == nullptr) {
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
 * Removes all elements of the list except for the head element, which points to nullptr.
 */
void List_h::clear() {
    INode* current = head->getNext(); // jesli head wskazuje na nullptr - brak elementów
    INode* next = nullptr;

    while (current != nullptr){
        next = current->getNext();
        delete current;
        current = next;
    }

    head->setNext(nullptr);
    size = 0;
}

/**
 * Returns data on given index
 * @param index
 * @return
 */
std::optional<int> List_h::get(int index) {
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

/**
 * Inserts element on front
 * @param data
 */
void List_h::insertFront(int data) {
    INode* buf = new Node(head->getNext(), data);
    head->setNext(buf);
    size++;
}

/**
 * Inserts element on given index if possible
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
void List_h::insertBack(int data) {
    if(size == 0) {
        insertFront(data);
    } else {
        INode* old = head->getNext();
        for(int i = 0; i < size - 1 ; i++){ // musimy dotrzeć do ostatniego elementu
            old = old->getNext();
        }
        INode* buf = new Node(nullptr, data);
        old->setNext(buf);
        size++;
    }

}

/**
 * Removes first element from list
 * @return data from removed element
 */
std::optional<int> List_h::removeFront() {
    INode* current = head->getNext(); // jesli head wskazuje na nullptr - brak elementów

    if(current != nullptr)
    {
        INode* next = current->getNext();
        int data = dynamic_cast<Node*>(current)->getData();
        delete current;
        head->setNext(next);
        size--;
        return data;
    } else {
        return std::nullopt; // Lista jest pusta, nie ma czego zwrócić.
    }
}

/**
 * Removes element from the given index from list
 * @return data from removed element
 */
std::optional<int> List_h::remove(int index) {
    if(index >= size || index < 0 ) return std::nullopt;
    if(index == 0) return removeFront();

    INode* current = head->getNext();// jesli head wskazuje na nullptr - brak elementów

    for(int i = 0; i < index - 1 ; i++){ // musimy dotrzeć do node o indeksie "index-1"
        current = current->getNext();
    }
    INode* next = current->getNext();
    int data = dynamic_cast<Node*>(next)->getData();
    current->setNext(next->getNext());
    delete next;
    size--;
    return data;
}

/**
 * Removes element from the end of list
 * @return data from removed element
 */
std::optional<int> List_h::removeBack() {
    return remove(size-1);
}

/**
 * Searches for given data and returns index
 * @param data
 * @return -1 - not found
 * @return >0 - found index
 */
int List_h::find(int data) {
    INode* current = head->getNext();// jesli head wskazuje na nullptr - brak elementów
    int i = 0;
    int found;
    while (i < size){
        found = dynamic_cast<Node*>(current)->getData();
        if ( found == data) return i;
        else {
            i++;
            current = current->getNext();
        }
    }
    return -1;

}