//
// Created by grzegorz on 25.03.24.
//

#ifndef LISTY_IDATASTRUCTURE_H
#define LISTY_IDATASTRUCTURE_H

#include <optional>

class IDataStructure{
public:
    virtual ~IDataStructure() = default;

    /**
     * Function chcecks if data structure is empty
     * @return 0 - not empty
     * @return 1 - empty
     */
    virtual int isEmpty() = 0;

    /**
     * Returns number of elements in data structure
     * @return size
     */
    virtual int getSize() = 0;

    /**
     * Init data structure - it is necessary for fast initzialization of data structure
     */
    virtual void init(int data) = 0;

    /**
     * Inserts element on front
     * @param data
     */
    virtual void insertFront(int data) = 0;

    /**
     * Inserts element on given index if possible
     * @param data
     * @param index
     * @return 0 - success
     * @return 1 - fail
     */
    virtual int insert(int index, int data) = 0;

    /**
     * Inserts element to the end of data structure
     * @param data
     */
    virtual void insertBack(int data) = 0;

    /**
     * Removes first element from data structure
     * @return data from removed element - if index ok
     * @return std::nullopt - if empty
     */
    virtual std::optional<int> removeFront() = 0;

    /**
     * Removes element from the given index from data structure
     * @return data from removed element - if index ok
     * @return std::nullopt - if wrong index
     */
    virtual std::optional<int> remove(int index) = 0;

    /**
     * Removes element from the end of data structure
     * @return data from removed element - if index ok
     * @return std::nullopt - if empty
     */
    virtual std::optional<int> removeBack() = 0;

    /**
     * Returns data on given index
     * @param index
     * @return data - if index ok
     * @return std::nullopt - if index wrong
     */
    virtual std::optional<int> get(int index) = 0;

    /**
     * Searches for given data and returns index
     * @param data
     * @return -1 - not found
     * @return >0 - found index
     */
    virtual int find(int data) = 0;
};

#endif //LISTY_IDATASTRUCTURE_H
