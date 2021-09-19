#include "ArrayStack.h"
#include "../../util/StringException.h"
#include <iostream>
template<typename E>
ArrayStack<E>::ArrayStack(int size) {
    maxSize = size;
    listArray = new E[maxSize];
    top = 0;
}

template<typename E>
ArrayStack<E>::~ArrayStack() {
    delete[] listArray;
}

template<typename E>
void ArrayStack<E>::clear() {
    // 注意这种写法，不需要将站内元素清零（浪费时间且无用）
    top = 0;
}

template<typename E>
void ArrayStack<E>::push(const E &item) {
    if (top >= maxSize) throw StringException("ArrayStack::push()==>max capacity");
    listArray[top++] = item;
}

template<typename E>
E ArrayStack<E>::pop() {
    if (top == 0) throw StringException("ArrayStack::pop()==>no element");
    return listArray[--top];
}

template<typename E>
const E &ArrayStack<E>::topValue() const {
    if (top == 0) throw StringException("ArrayStack::topValue()==>no element");
    return listArray[top - 1];
}

template<typename E>
int ArrayStack<E>::length() const {
    return top;
}

template<typename E>
void ArrayStack<E>::show() const {
    std::cout << "ArrayStack[";
    for (int i = top -1; i >= 0; --i) {
        std::cout << listArray[i] << " >> ";
    }
    std::cout << "]" << std::endl;
}
