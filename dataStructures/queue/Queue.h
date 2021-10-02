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
    // ��ն���
    virtual void clear() = 0;
    // ���
    virtual void enqueue(const E&) = 0;
    // ����
    virtual E dequeue() = 0;
    // ��ȡ����Ԫ��ֵ
    virtual const E& frontValue() const = 0;
    // ��ȡ�ӳ���
    virtual int length() const = 0;

    // �Զ��巽�����
    virtual void show() const = 0;
};


#endif //ALGORITHM_QUEUE_H