#include <iostream>
#include "LinkedList.h"

template<typename E>
void LinkedList<E>::init() {
    head = curr = tail = new Node<E>(nullptr);
    cnt = 0;
}

template<typename E>
void LinkedList<E>::removeAll() {
    while (head != tail) {
        curr = head;
        head = head->next;
        delete curr;
    }
    delete head;
}

template<typename E>
void LinkedList<E>::clear() {
    removeAll();
    init();
}

template<typename E>
void LinkedList<E>::insert(const E &item) {
    if (curr == tail || cnt == 0) append(item);
    else {
        curr->next = new Node<E>(item, curr->next->next);
        cnt ++;
    }
}

template<typename E>
void LinkedList<E>::append(const E &item) {
    tail->next = new Node<E>(item, nullptr);
    tail = tail->next;
    cnt ++;
}

template<typename E>
E LinkedList<E>::remove() {
    Node<E>* tmp = curr->next;
    curr->next = curr->next->next;
    E data = tmp->data;
    cnt --;
    delete tmp;
    return data;
}

template<typename E>
void LinkedList<E>::moveToStart() {
    curr = head;
}

template<typename E>
void LinkedList<E>::moveToEnd() {
    curr = tail;
}

template<typename E>
void LinkedList<E>::moveToPos(int pos) {
    if (0 <= pos && pos <= cnt) {
        curr = head;
        for (int i = pos; i > 0 ; --i) {
            curr = curr->next;
        }
    } else std::cout << "index out of range" << std::endl;
}

template<typename E>
void LinkedList<E>::prev() {
    Node<E>* i = head;
    while (i->next != curr) {
        i = i->next;
    }
}

template<typename E>
void LinkedList<E>::next() {
    curr = curr->next;
}

template<typename E>
int LinkedList<E>::currPos() const {
    Node<E>* i = head;
    int pos = 0;
    while (i != curr) {
        pos ++;
        i = i->next;
    }
    return pos;
}

template<typename E>
int LinkedList<E>::length() const {
    return cnt;
}

template<typename E>
const E &LinkedList<E>::getValue() const {
    return curr->next->data;
}
