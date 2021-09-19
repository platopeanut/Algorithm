#include "LinkedStack.h"
#include "../../util/StringException.h"
#include <iostream>

template<typename E>
LinkedStack<E>::LinkedStack() {
    top = nullptr;
    size = 0;
}

template<typename E>
LinkedStack<E>::~LinkedStack() {
    clear();
}

template<typename E>
void LinkedStack<E>::clear() {
    while (top != nullptr) {
        NodeWithPool<E>* tmp = top;
        top = top->next;
        delete tmp;
    }
    size = 0;
}

template<typename E>
void LinkedStack<E>::push(const E &item) {
    top = new NodeWithPool<E>(item, top);
    size ++;
}

template<typename E>
E LinkedStack<E>::pop() {
    if (size == 0) throw StringException("LinkedStack::pop()==>the stack is empty");
    NodeWithPool<E>* tmp = top;
    top = top->next;
    E data = tmp->data;
    delete tmp;
    size --;
    return data;
}

template<typename E>
const E &LinkedStack<E>::topValue() const {
    if (size == 0) throw StringException("LinkedStack::topValue()==>No element");
    return top->data;
}

template<typename E>
int LinkedStack<E>::length() const {
    return size;
}

template<typename E>
void LinkedStack<E>::show() const {
    std::cout << "LinkedStack[";
    NodeWithPool<E>* tmp = top;
    while (tmp != nullptr) {
        std::cout << tmp->data << " >> ";
        tmp = tmp->next;
    }
    std::cout << "]" << std::endl;
}
