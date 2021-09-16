#ifndef ALGORITHM_ARRAYSTACK_H
#define ALGORITHM_ARRAYSTACK_H

#include "Stack.h"
#define defaultSize 1024

template<typename E>
class ArrayStack : public Stack<E>{
private:
    int maxSize;
    // top表示当前最顶端元素索引的上一个
    int top;
    E* listArray;
public:
    ArrayStack(int size = defaultSize);
    virtual ~ArrayStack();
    virtual void clear();
    virtual void push(const E &item);
    virtual E pop();
    virtual const E &topValue() const;
    virtual int length() const;

    virtual void show() const;
};

#endif //ALGORITHM_ARRAYSTACK_H
