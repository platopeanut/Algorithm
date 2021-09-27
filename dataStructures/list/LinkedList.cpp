#include <iostream>
#include "LinkedList.h"
#include "../../util/StringException.h"

// TODO:moveToEndʹcurrָ��tailǰһ��
// ��ǰ���⣺moveToEnd,remove����ɾ�����һ��
// ����tailǰ�ڵ㻺��
// insert�����ж�ĩβ

template<typename E>
void LinkedList<E>::init() {
    head = curr = tail = new Node<E>;
    cnt = 0;
}

template<typename E>
void LinkedList<E>::removeAll() {
    while (head != nullptr) {
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
    // ����tail
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
    // ��������Ϊ0ʱ����curr==tailʱ
    if (curr->next == nullptr) throw StringException("LinkedList::remove()==>No element");
    // ��Ҫɾ����βʱ��Ҫ��������tail
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
    // ע������pos����ȡ��cnt������ADT�淶
    if (0 <= pos && pos <= cnt) {
        curr = head;
        // ִ��pos��
        for (int i = pos; i > 0 ; --i) {
            curr = curr->next;
        }
    } else throw StringException("LinkedList::moveToPos()==>index out of range");
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
    if (curr->next == nullptr) throw StringException("LinkedList::getValue()==>No Value");
    return curr->next->data;
}

template<typename E>
void LinkedList<E>::print() const {
    std::cout << "LinkedList[";
    for (Node<E>* i = head->next; i != nullptr; i = i->next ) {
        std::cout << i->data << ", ";
    }
    std::cout << "]" << std::endl;
}

template<typename E>
void LinkedList<E>::setValue(const E &item) {
    if (curr != tail) {
        curr->next->data = item;
    } else throw StringException("LinkedList::setValue()==>No Element");
}

// chapter4_6
template<typename E>
void LinkedList<E>::reverse() {
    tail = head->next;
    if (tail == nullptr) return;
    while (tail->next != nullptr) {
        curr = tail->next;
        tail->next = curr->next;
        curr->next = head->next;
        head->next = curr;
    }
}
