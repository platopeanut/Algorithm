#include "DoublyLinkedList.h"
#include "../../util/StringException.h"


// TODO:依然存在单向链表的逻辑问题，insert与remove处理表尾元素不兼容

template<typename E>
void DoublyLinkedList<E>::init() {
    head = new DoublyNode<E>;
    tail = new DoublyNode<E>(head, nullptr);
    head->next = tail;
    cnt = 0;
    curr = head;
}

template<typename E>
void DoublyLinkedList<E>::removeAll() {
    curr = head;
    while (head != tail) {
        head = head->next;
        delete curr;
        curr = head;
    }
    delete tail;
}

template<typename E>
void DoublyLinkedList<E>::insert(const E &item) {
    // 这里curr->next 与 curr->next->prev 位置顺序很重要
    curr->next = curr->next->prev = new DoublyNode<E>(item, curr, curr->next);
    cnt ++;
}

template<typename E>
void DoublyLinkedList<E>::append(const E &item) {
    tail->prev = tail->prev->next = new DoublyNode<E>(item, tail->prev, tail);
    cnt ++;
}

template<typename E>
E DoublyLinkedList<E>::remove() {
    // 包含长度为0，以及curr在tail.prev时两种情况
    if (curr->next == tail) throw StringException("DoublyLinkedList::remove()==>No element");
    DoublyNode<E>* tmp = curr->next;
    E data = tmp->data;
    curr->next = curr->next->next;
    curr->next->prev = curr;
    cnt --;
    delete tmp;
    return data;
}

template<typename E>
void DoublyLinkedList<E>::moveToStart() {
    curr = head;
}

template<typename E>
void DoublyLinkedList<E>::moveToEnd() {
    curr = tail->prev;
}

template<typename E>
void DoublyLinkedList<E>::moveToPos(int pos) {
    if (pos < 0 || pos >= cnt) throw StringException("DoublyLinkedList::moveToPos()==>index out of range");
    curr = head;
    for (int i = 0; i < pos; ++i) {
        curr = curr->next;
    }
}

template<typename E>
void DoublyLinkedList<E>::prev() {
    if (curr != head)
    curr = curr->prev;
}

template<typename E>
void DoublyLinkedList<E>::next() {
    if (curr != tail->prev)
    curr = curr->next;
}

template<typename E>
int DoublyLinkedList<E>::currPos() const {
    DoublyNode<E>* tmp = head;
    int pos = 0;
    while (tmp != curr) {
        tmp = tmp->next;
        pos ++;
    }
    return pos;
}

template<typename E>
int DoublyLinkedList<E>::length() const {
    return cnt;
}

template<typename E>
const E &DoublyLinkedList<E>::getValue() const {
    return curr->next->data;
}

template<typename E>
void DoublyLinkedList<E>::setValue(const E &item) {
    if (curr->next == tail) throw StringException("DoublyLinkedList::setValue()==>No element");
    curr->next->data = item;
}
