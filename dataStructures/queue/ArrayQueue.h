#ifndef ALGORITHM_ARRAYQUEUE_H
#define ALGORITHM_ARRAYQUEUE_H

#include "Queue.h"
#define defaultSize 1024
template <typename E>
class ArrayQueue : public Queue<E>{
private:
    E* listArray;
    int front;
public:
    ArrayQueue(int size = defaultSize);
    virtual ~ArrayQueue();
    virtual void clear();
    virtual void enqueue(const E &e);
    virtual E dequeue();
    virtual const E &frontValue() const;
    virtual int length() const;
};
#endif //ALGORITHM_ARRAYQUEUE_H
