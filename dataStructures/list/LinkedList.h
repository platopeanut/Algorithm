
#ifndef ALGORITHM_LINKEDLIST_H
#define ALGORITHM_LINKEDLIST_H

#include "List.h"
#include "../node/Node.h"
template<typename E> class LinkedList : public List<E> {
private:
    Node<E>* head;
    Node<E>* curr;
    Node<E>* tail;
    // Á´±í³¤¶È
    int cnt = 0;
    void init();
    void removeAll();
public:
    LinkedList() {init();}
    ~LinkedList() {removeAll();}
    void print() const;
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




#endif //ALGORITHM_LINKEDLIST_H
