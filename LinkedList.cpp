#include <iostream>
#include "LinkedList.h"

template<typename E>
void LinkedList<E>::init() {
    head = curr = tail = new Node<E>;
    cnt = 0;
}

template<typename E>
void LinkedList<E>::removeAll() {
    while (head != NULL) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

template<typename E>
void LinkedList<E>::clear() {
    removeAll();
    init();
}

template<typename E>
void LinkedList<E>::insert(const E &item) {
    curr->next = new Node<E>(item, curr->next);
    // 更新tail
    if (curr == tail) tail = tail->next;
    cnt ++;
}

template<typename E>
void LinkedList<E>::append(const E &item) {
    tail->next = new Node<E>(item, nullptr);
    tail = tail->next;
    cnt ++;
}

template<typename E>
E LinkedList<E>::remove() {
    // 包括长度为0时，当curr==tail时
    if (curr->next == NULL) {
        std::cout << "No Element" << std::endl;
        return NULL;
    }
    // 当要删除表尾时需要重新声明tail
    if (curr->next == tail) {
        tail = curr;
    }
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
    // 注意这里pos可以取到cnt，属于ADT规范
    if (0 <= pos && pos <= cnt) {
        curr = head;
        // 执行pos次
        for (int i = pos; i > 0 ; --i) {
            curr = curr->next;
        }
    } else std::cout << "index out of range" << std::endl;
}

template<typename E>
void LinkedList<E>::prev() {
    if (curr == head) return;
    Node<E>* i = head;
    while (i->next != curr) {
        i = i->next;
    }
    curr = i;
}

template<typename E>
void LinkedList<E>::next() {
    if (curr == tail) return;
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
    // when curr == tail
    if (curr->next == NULL) {
        std::cout << "No Value" << std::endl;
        return NULL;
    }
    return curr->next->data;
}

template<typename E>
void LinkedList<E>::print() const {
    std::cout << "LinkedList[";
    for (Node<E>* i = head->next; i != NULL; i = i->next ) {
        std::cout << i->data << ", ";
    }
    std::cout << "]" << std::endl;
}
