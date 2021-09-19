#ifndef ALGORITHM_LINKEDQUEUE_H
#define ALGORITHM_LINKEDQUEUE_H

#include "Queue.h"
#include "../node/NodeWithPool.h"

template<typename E>
class LinkedQueue : public Queue<E>{
private:
    NodeWithPool<E>* front;
    NodeWithPool<E>* rear;
    int size;
public:
    LinkedQueue();
    virtual ~LinkedQueue() {clear();delete front;}
    virtual void clear();
    virtual void enqueue(const E &e);
    virtual E dequeue();
    virtual const E &frontValue() const;
    virtual int length() const;
    virtual void show() const;
};

#endif //ALGORITHM_LINKEDQUEUE_H
