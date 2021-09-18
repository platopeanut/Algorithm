#ifndef ALGORITHM_DOUBLYLINKEDLIST_H
#define ALGORITHM_DOUBLYLINKEDLIST_H

#include "List.h"
#include "../node/DoublyNode.h"

// ˫����������ڵ�������ȱ�����ڿռ���Դ��
// ���������һ��������ʹ���������ÿ���ڵ�洢һ��ָ��ֵ��prev��next�����
// ԭ�� (L^R)^L = R, (L^R)^R = L
template<typename E> class DoublyLinkedList : public List<E> {
private:
    DoublyNode<E>* head;
    DoublyNode<E>* tail;
    // �˰汾�У�curr����ָ���߼�λ�õ�ǰһ�ڵ�
    // curr ��ΧΪ��head ==> tail->prev
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
