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
    virtual void clear() = 0;
    virtual void push(const E& item) = 0;
    virtual E pop() = 0;
    virtual const E& topValue() const = 0;
    virtual int length() const = 0;

    // 自定义方便测试
    virtual void show() const = 0;

};
#endif //ALGORITHM_STACK_H
