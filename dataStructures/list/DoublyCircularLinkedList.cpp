#include "DoublyCircularLinkedList.h"

#include "../node/DoublyNode.h"
#include "../../util/StringException.h"

template<typename E>
void DoublyCircularLinkedList<E>::init() {
    // 设计：tail不单独分配空间，总是head的prev
    // 定义tail是为了后续处理逻辑上的方便
    // curr除了长度为0时在head处，其他时候保证不能在head处
    head = new DoublyNode<E>;
    curr = tail = head;
    head->prev = tail;
    head->next = tail;
    size = 0;
}

template<typename E>
void DoublyCircularLinkedList<E>::removeAll() {
    while (head != tail) {
        curr = head;
        head = head->next;
        delete curr;
    }
    delete tail;
}

template<typename E>
void DoublyCircularLinkedList<E>::insert(const E &item) {
    auto* tmp = new DoublyNode<E>(item, curr->prev, curr);
    curr->prev->next = tmp;
    tmp->next->prev = tmp;
    if (size == 0) {
        tail = curr = curr->next;
    }
    size ++;
}

template<typename E>
void DoublyCircularLinkedList<E>::append(const E &item) {
    head->prev = tail->next = new DoublyNode<E>(item, tail, head);
    tail = tail->next;
    if (size == 0) curr = curr->next;
    size ++;
}

template<typename E>
E DoublyCircularLinkedList<E>::remove() {
    if (size == 0) throw StringException("DoublyCircularLinkedList::remove()==>No element");
    auto* tmp = curr;
    curr = curr->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
    size --;
}

template<typename E>
void DoublyCircularLinkedList<E>::moveToStart() {
    curr = head->next;
}

template<typename E>
void DoublyCircularLinkedList<E>::moveToEnd() {
    curr = tail;
}

template<typename E>
void DoublyCircularLinkedList<E>::moveToPos(int pos) {
    curr = head->next;
    for (int i = 0; i < pos; ++i) {
        curr = curr->next;
        // curr不能在head上，下同
        if (curr == head) curr = curr->next;
    }
}

template<typename E>
void DoublyCircularLinkedList<E>::prev() {
    curr = curr->prev;
    if (curr == head) curr = curr->prev;
}

template<typename E>
void DoublyCircularLinkedList<E>::next() {
    curr = curr->next;
    if (curr == head) curr = curr->next;
}

template<typename E>
int DoublyCircularLinkedList<E>::currPos() const {
    auto* tmp = head->next;
    int i = 0;
    while (tmp != curr) {
        tmp = tmp->next;
        i ++;
    }
    return i;
}

template<typename E>
int DoublyCircularLinkedList<E>::length() const {
    return size;
}

template<typename E>
const E &DoublyCircularLinkedList<E>::getValue() const {
    if (size == 0) throw StringException("DoublyCircularLinkedList<E>::getValue()==>No Value");
    return curr->data;
}

template<typename E>
void DoublyCircularLinkedList<E>::setValue(const E &item) {
    if (size == 0) throw StringException("DoublyCircularLinkedList<E>::getValue()==>No Value");
    curr->data = item;
}
