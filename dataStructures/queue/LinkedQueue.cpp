#include "LinkedQueue.h"
#include "../../util/StringException.h"
#include <iostream>

template<typename E>
LinkedQueue<E>::LinkedQueue() {
    front = rear = new NodeWithPool<E>;
    size = 0;
}

template<typename E>
void LinkedQueue<E>::clear() {
    // 重置到初始化状态
    while (front != rear) {
        NodeWithPool<E>* tmp = front;
        front = front->next;
        delete tmp;
    }
    size = 0;
}

template<typename E>
void LinkedQueue<E>::enqueue(const E &item) {
    rear = rear->next = new NodeWithPool<E>(item, nullptr);
    size ++;
}

template<typename E>
E LinkedQueue<E>::dequeue() {
    if (size == 0) throw StringException("LinkedQueue::dequeue()==>Queue empty");
    NodeWithPool<E>* tmp = front->next;
    E data = tmp->data;
    front->next = front->next->next;
    // 注意删除队尾时
    if (tmp == rear) rear = front;
    delete tmp;
    size --;
    return data;
}

template<typename E>
const E &LinkedQueue<E>::frontValue() const {
    if (size == 0) throw StringException("LinkedQueue::dequeue()==>Queue empty");
    return front->next->data;
}

template<typename E>
int LinkedQueue<E>::length() const {
    return size;
}

template<typename E>
void LinkedQueue<E>::show() const {
    std::cout << "LinkedQueue[";
    for (NodeWithPool<E>* i = front->next; i != nullptr ; i = i->next) {
        std::cout << i->data << ' ';
    }
    std::cout << ']' << std::endl;
}
