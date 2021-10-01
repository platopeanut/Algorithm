#ifndef ALGORITHM_DOUBLYCIRCULARLINKEDLIST_H
#define ALGORITHM_DOUBLYCIRCULARLINKEDLIST_H

#include "./List.h"
#include "../node/DoublyNode.h"
template<typename E>
class DoublyCircularLinkedList: public List<E>{
private:
    DoublyNode<E>* head;
    DoublyNode<E>* tail;
    // curr 就是逻辑当前节点
    DoublyNode<E>* curr;
    int size = 0;
    void init();
    void removeAll();
public:
    DoublyCircularLinkedList() {init();}
    virtual ~DoublyCircularLinkedList() {removeAll();}
    virtual void clear() {removeAll();init();}
    virtual void insert(const E &item);
    virtual void append(const E &item);
    virtual E remove();
    virtual void moveToStart();
    virtual void moveToEnd();
    virtual void moveToPos(int pos);
    virtual void prev();
    virtual void next();
    virtual int currPos() const;
    virtual int length() const;
    virtual const E &getValue() const;
    virtual void setValue(const E &item);
};
#endif //ALGORITHM_DOUBLYCIRCULARLINKEDLIST_H
