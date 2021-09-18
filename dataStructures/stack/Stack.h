#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

template<typename E>
class Stack {
private:
    void operator =(const Stack&) {}
    Stack(const Stack&) {}

public:
    Stack() {}
    virtual ~Stack() {}
    // ���ջ
    virtual void clear() = 0;
    // ��ջ
    virtual void push(const E& item) = 0;
    // ��ջ
    virtual E pop() = 0;
    // ��ȡջ��ֵ
    virtual const E& topValue() const = 0;
    // ��ȡջ����
    virtual int length() const = 0;

    // �Զ��巽�����
    virtual void show() const = 0;

};
#endif //ALGORITHM_STACK_H
