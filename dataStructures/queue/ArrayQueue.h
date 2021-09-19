#ifndef ALGORITHM_ARRAYQUEUE_H
#define ALGORITHM_ARRAYQUEUE_H
/**
 * 顺序队列实现关键：
 *      - 循环数组：
 *          - 索引取模
 *      - 空队列与满队列区分：
 *          - 方法一：设置队列长度变量或者是否为空标志布尔变量
 *          - 方法二：实际队列长度 = 逻辑队列长度 + 1
 * 此实现种采取方法二，front前一个位置不存储值
 */
#include "Queue.h"
#define defaultSize 1024
template <typename E>
class ArrayQueue : public Queue<E>{
private:
    E* listArray;
    int maxSize; // 逻辑队列长度+1
    int front; // 队首索引
    int rear; // 队尾索引
public:
    ArrayQueue(int size = defaultSize);
    virtual ~ArrayQueue();
    virtual void clear();
    virtual void enqueue(const E &e);
    virtual E dequeue();
    virtual const E &frontValue() const;
    virtual int length() const;

    virtual void show() const;
};
#endif //ALGORITHM_ARRAYQUEUE_H
