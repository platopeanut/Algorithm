
#ifndef ALGORITHM_LINKEDLIST_H
#define ALGORITHM_LINKEDLIST_H

#include "List.h"
#include "Node.h"
template<typename E> class LinkedList : public List<E> {
private:
    Node<E>* head;
    Node<E>* curr;
    Node<E>* tail;
    // Á´±í³¤¶È
    int cnt;
    void init();
    void removeAll();
public:
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
};




#endif //ALGORITHM_LINKEDLIST_H
