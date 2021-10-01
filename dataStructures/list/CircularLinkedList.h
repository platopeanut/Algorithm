#ifndef ALGORITHM_CIRCULARLINKEDLIST_H
#define ALGORITHM_CIRCULARLINKEDLIST_H

#include "List.h"
#include "../node/NodeWithPool.h"
template<typename E>
class CircularLinkedList : public List<E>{
private:
    NodeWithPool<E>* head;
    NodeWithPool<E>* tail;
    NodeWithPool<E>* curr;
    int size;
    void init();
    void removeAll();
public:
    CircularLinkedList() {init();}
    ~CircularLinkedList() {removeAll();}
    virtual void clear();
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

#endif //ALGORITHM_CIRCULARLINKEDLIST_H
