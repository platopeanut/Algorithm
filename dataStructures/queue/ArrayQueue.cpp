#include "ArrayQueue.h"
#include "../../util/StringException.h"
#include <iostream>

template<typename E>
ArrayQueue<E>::ArrayQueue(int size) {
    maxSize = size + 1;
    listArray = new E[maxSize];
    front = 1;
    rear = 0;
}

template<typename E>
ArrayQueue<E>::~ArrayQueue() {
    delete[] listArray;
}

template<typename E>
void ArrayQueue<E>::clear() {
    front = 1;
    rear = 0;
}

template<typename E>
void ArrayQueue<E>::enqueue(const E &item) {
    // real不能在font前一个位置
    if ((rear + 2) % maxSize == front) throw StringException("ArrayQueue::enqueue()==>Queue MAX capacity");
    rear = (rear+1) % maxSize;
    listArray[rear] = item;
}

template<typename E>
E ArrayQueue<E>::dequeue() {
    if (length() == 0) throw StringException("ArrayQueue::dequeue()==>Queue empty");
    E data = listArray[front];
    front = (front+1) % maxSize;
    return data;
}

template<typename E>
const E &ArrayQueue<E>::frontValue() const {
    if (length() == 0) throw StringException("ArrayQueue::frontValue()==>Queue empty");
    return listArray[front];
}

template<typename E>
int ArrayQueue<E>::length() const {
    return ((rear + maxSize) - front + 1) % maxSize;
}

template<typename E>
void ArrayQueue<E>::show() const {
    std::cout << "ArrayQueue[";
    for (int i = front; i != (rear+1)%maxSize; i = (i+1)%maxSize) {
        std::cout << listArray[i] << " ";
    }
    std::cout << ']' << std::endl;
}
