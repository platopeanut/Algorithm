#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#include <iostream>

template <typename E> class List {
private:
    void operator= (const List&) {}
    List(const List&) = default;

public:
    List() = default;
    virtual ~List() = default;

    virtual void clear() = 0;
    // �ڵ�ǰλ�ò���Ԫ��
    virtual void insert(const E& item) = 0;
    // �ڱ�β���Ԫ��
    virtual void append(const E& item) = 0;
    // ɾ����ǰλ��Ԫ�ز�����
    virtual E remove() = 0;
    // �ƶ���ǰλ��
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void moveToPos(int pos) = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    // ��ȡ��ǰλ��
    virtual int currPos() const = 0;
    // ��ȡ����
    virtual int length() const = 0;
    // ��ȡ��ǰλ�ö�Ӧֵ
    virtual const E& getValue() const = 0;
    // �Ե�ǰλ��ֵ�����޸ġ��Զ��塿
    virtual void setValue(const E& item) = 0;
};

#endif //ALGORITHM_LIST_H
