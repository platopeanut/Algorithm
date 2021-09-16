#include "DoublyLinkedList.h"

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

}

template<typename E>
void DoublyLinkedList<E>::append(const E &item) {
    tail->prev = tail->prev->next = new DoublyNode<E>(item, tail->prev, tail);
    cnt ++;
}

template<typename E>
E DoublyLinkedList<E>::remove() {
    return nullptr;
}

template<typename E>
void DoublyLinkedList<E>::moveToStart() {
    curr = head;
}

template<typename E>
void DoublyLinkedList<E>::moveToEnd() {
    curr = tail->prev->prev;
}

template<typename E>
void DoublyLinkedList<E>::moveToPos(int pos) {

}

template<typename E>
void DoublyLinkedList<E>::prev() {

}

template<typename E>
void DoublyLinkedList<E>::next() {

}

template<typename E>
int DoublyLinkedList<E>::currPos() const {
    return 0;
}

template<typename E>
int DoublyLinkedList<E>::length() const {
    return 0;
}

template<typename E>
const E &DoublyLinkedList<E>::getValue() const {
    return NULL;
}

template<typename E>
void DoublyLinkedList<E>::setValue(const E &item) {

}
