#ifndef ALGORITHM_DOUBLYLINKEDLIST_H
#define ALGORITHM_DOUBLYLINKEDLIST_H

#include "List.h"
#include "../node/DoublyNode.h"

// 双向链表相较于单向链表，缺点在于空间资源大
// 解决上述的一个方案：使用异或函数，每个节点存储一个指针值：prev与next的异或
// 原理： (L^R)^L = R, (L^R)^R = L
template<typename E> class DoublyLinkedList : public List<E> {
private:
    DoublyNode<E>* head;
    DoublyNode<E>* tail;
    // 此版本中，curr依旧指向逻辑位置的前一节点
    // curr 范围为：head ==> tail->prev
    DoublyNode<E>* curr;
    int cnt = 0;
    void init();
    void removeAll();
public:
    DoublyLinkedList() {init();}
    virtual ~DoublyLinkedList() {removeAll();}
    virtual void clear() {removeAll();init();}
    virtual void insert(const E& item);
    virtual void append(const E& item);
    virtual E remove();
    virtual void moveToStart();
    virtual void moveToEnd();
    virtual void moveToPos(int pos);
    virtual void prev();
    virtual void next();
    virtual int currPos() const;
    virtual int length() const;
    virtual const E& getValue() const;

    virtual void setValue(const E &item);
};



#endif //ALGORITHM_DOUBLYLINKEDLIST_H
