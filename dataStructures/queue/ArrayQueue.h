#ifndef ALGORITHM_ARRAYQUEUE_H
#define ALGORITHM_ARRAYQUEUE_H
/**
 * ˳�����ʵ�ֹؼ���
 *      - ѭ�����飺
 *          - ����ȡģ
 *      - �ն��������������֣�
 *          - ����һ�����ö��г��ȱ��������Ƿ�Ϊ�ձ�־��������
 *          - ��������ʵ�ʶ��г��� = �߼����г��� + 1
 * ��ʵ���ֲ�ȡ��������frontǰһ��λ�ò��洢ֵ
 */
#include "Queue.h"
#define defaultSize 1024
template <typename E>
class ArrayQueue : public Queue<E>{
private:
    E* listArray;
    int maxSize; // �߼����г���+1
    int front; // ��������
    int rear; // ��β����
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
