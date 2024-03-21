//
// Created by Szymon on 21.03.2024.
//

#ifndef LISTY_LIST_HEAD_TAIL_H
#define LISTY_LIST_HEAD_TAIL_H
class List_h_t{
private:
    int size;
    int *head;
    int *tail;
    int *next;
public:
     void insert_at_begin();
    void insert_at_given();
    void insert_at_end();
    void delete_at_begin();
    void delete_at_given();
    void delete_at_end();

};
#endif //LISTY_LIST_HEAD_TAIL_H
