#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H

template<typename E>
class Queue {
private:
    void operator =(const Queue&) {}
    Queue(const Queue&) {}
public:
    Queue() {}
    virtual ~Queue() {}
    // 清空队列
    virtual void clear() = 0;
    // 入队
    virtual void enqueue(const E&) = 0;
    // 出队
    virtual E dequeue() = 0;
    // 获取队首元素值
    virtual const E& frontValue() const = 0;
    // 获取队长度
    virtual int length() const = 0;

    // 自定义方便测试
    virtual void show() const = 0;
};


#endif //ALGORITHM_QUEUE_H
