//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_DOUBLE_LINKED_LIST_H
#define LISTY_DOUBLE_LINKED_LIST_H

class DLL{
private:
    int size;
    int *prev;
    int *next;
    int *head;
    int *tail;
public:
    void insert_at_begin();
    void insert_at_given();
    void insert_at_end();
    void delete_at_begin();
    void delete_at_given();
    void delete_at_end();

};

#endif //LISTY_DOUBLE_LINKED_LIST_H
