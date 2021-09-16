#ifndef ALGORITHM_LINKEDSTACK_H
#define ALGORITHM_LINKEDSTACK_H

#include "Stack.h"
#include "../node/NodeWithPool.h"

template<typename E>
class LinkedStack : public Stack<E>{
private:
    NodeWithPool<E>* top;
    int size;
public:
    LinkedStack();
    virtual ~LinkedStack();
    virtual void clear();
    virtual void push(const E &item);
    virtual E pop();
    virtual const E &topValue() const;
    virtual int length() const;
    virtual void show() const;
};

#endif //ALGORITHM_LINKEDSTACK_H
