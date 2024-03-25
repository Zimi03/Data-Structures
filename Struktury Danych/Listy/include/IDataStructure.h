//
// Created by grzegorz on 25.03.24.
//

#ifndef LISTY_IDATASTRUCTURE_H
#define LISTY_IDATASTRUCTURE_H
#include <optional>

class IDataStructure{
public:
    virtual ~IDataStructure() = default;

    virtual void insertFront(int data) = 0;
    virtual int insert(int index, int data) = 0;
    virtual void insertBack(int data) = 0;

    virtual std::optional<int> removeFront() = 0;
    virtual std::optional<int> remove(int index) = 0;
    virtual std::optional<int> removeBack() = 0;

    virtual std::optional<int> get(int index) = 0;
    virtual int find(int data) = 0;
};

#endif //LISTY_IDATASTRUCTURE_H
