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
    // ʹ�½ڵ�ָ��head
    tail->next = new NodeWithPool<E>(item, tail->next);
    tail = tail->next;
    size ++;
}

template<typename E>
E CircularLinkedList<E>::remove() {
    if (curr->next == tail) {
        tail = curr;
//        ע�⣺���ﲻҪ��ôд���״�
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
    // ������Ƴ�û������
    if (pos >= 0) {
        curr = head;
        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
    } else throw StringException("CircularLinkedList::moveToPos()==>index out of range");
}

template<typename E>
void CircularLinkedList<E>::prev() {
    // ��ʱ�κν�㶼��ǰһ�ڵ�
    auto* tmp = head;
    while (tmp->next != curr) {
        tmp = tmp->next;
    }
    curr = tmp;
}

template<typename E>
void CircularLinkedList<E>::next() {
    // �κνڵ㶼�к�ڵ�
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
    // when curr == tail���⴦��
    if (curr == tail) return tail->data;
    return curr->next->data;
}

template<typename E>
void CircularLinkedList<E>::setValue(const E &item) {
    // when curr == tail���⴦��
    if (curr == tail) {
        tail->data = item;
        return;
    }
    curr->next->data = item;
}
