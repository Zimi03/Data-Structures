//
// Created by grzegorz on 22.03.24.
//

#ifndef LISTY_INODE_H
#define LISTY_INODE_H


class INode {
public:
    virtual INode* getNext() = 0;
    virtual void setNext(INode* next) = 0;
    virtual ~INode() = default;

};


#endif //LISTY_INODE_H
