#include "CircularLinkedList.h"
#include "../node/NodeWithPool.h"
#include "../../util/StringException.h"
template<typename E>
void CircularLinkedList<E>::init() {
    tail = head = curr = new NodeWithPool<E>;
    tail->next = head;
}

template<typename E>
void CircularLinkedList<E>::removeAll() {
    while (head != tail) {
        curr = head;
        head = head->next;
        delete curr;
    }
    delete tail;
}

template<typename E>
void CircularLinkedList<E>::clear() {
    removeAll();
    init();
}

template<typename E>
void CircularLinkedList<E>::insert(const E &item) {
    curr->next = new NodeWithPool<E>(item, curr->next);
    if (curr == tail) tail = tail->next;
    size ++;
}

template<typename E>
void CircularLinkedList<E>::append(const E &item) {
    // 使新节点指向head
    tail->next = new NodeWithPool<E>(item, tail->next);
    tail = tail->next;
    size ++;
}

template<typename E>
E CircularLinkedList<E>::remove() {
    if (curr->next == tail) {
        tail = curr;
//        注意：这里不要这么写！易错！
//        tail->next = head;
    }
    NodeWithPool<E>* tmp = curr->next;
    E data = tmp->data;
    curr->next = curr->next->next;
    size --;
    delete tmp;
    return data;
}

template<typename E>
void CircularLinkedList<E>::moveToStart() {
    curr = head;
}

template<typename E>
void CircularLinkedList<E>::moveToEnd() {
    curr = tail;
}

template<typename E>
void CircularLinkedList<E>::moveToPos(int pos) {
    // 这里设计成没有上限
    if (pos >= 0) {
        curr = head;
        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
    } else throw StringException("CircularLinkedList::moveToPos()==>index out of range");
}

template<typename E>
void CircularLinkedList<E>::prev() {
    // 此时任何结点都有前一节点
    auto* tmp = head;
    while (tmp->next != curr) {
        tmp = tmp->next;
    }
    curr = tmp;
}

template<typename E>
void CircularLinkedList<E>::next() {
    // 任何节点都有后节点
    curr = curr->next;
}

template<typename E>
int CircularLinkedList<E>::currPos() const {
    int i = 0;
    auto* tmp = head;
    while (tmp != curr) {
        i ++;
        tmp = tmp->next;
    }
    return i;
}

template<typename E>
int CircularLinkedList<E>::length() const {
    return size;
}

template<typename E>
const E &CircularLinkedList<E>::getValue() const {
    // when curr == tail特殊处理
    if (curr == tail) return tail->data;
    return curr->next->data;
}

template<typename E>
void CircularLinkedList<E>::setValue(const E &item) {
    // when curr == tail特殊处理
    if (curr == tail) {
        tail->data = item;
        return;
    }
    curr->next->data = item;
}
