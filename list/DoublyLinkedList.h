#ifndef ALGORITHM_DOUBLYLINKEDLIST_H
#define ALGORITHM_DOUBLYLINKEDLIST_H

#include "List.h"

template<typename E> class DoublyLinkedList : public List<E> {
private:
    
public:
    DoublyLinkedList(int size = defaultSize);
    virtual ~DoublyLinkedList();
    virtual void clear();
    virtual void insert(const E& item);
    virtual void append(const E& item);
    virtual E remove();
    virtual void moveToStart();
    virtual void moveToEnd();
    virtual void moveToPos(int pos);
    virtual void prev();
    virtual void next();
    virtual int currPos() const;
    virtual int length() const;
    virtual const E& getValue() const;

    virtual void setValue(const E &item);
};

#endif //ALGORITHM_DOUBLYLINKEDLIST_H
