#include "ArrayList.h"
#include <iostream>

template<typename E>
ArrayList<E>::ArrayList(int size) {
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
}

template<typename E>
ArrayList<E>::~ArrayList() {
    delete[] listArray;
}

template<typename E>
void ArrayList<E>::clear() {
    delete[] listArray;
    listSize = curr = 0;
    listArray = new E[maxSize];
}

template<typename E>
void ArrayList<E>::insert(const E& item) {
    if (listSize < maxSize) {
        for (int i = listSize; i > curr; --i) {
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = item;
        listSize++;
    }
    else std::cout << "max capacity" << std::endl;
}

template<typename E>
void ArrayList<E>::append(const E& item) {
    if (listSize < maxSize) {
        listArray[listSize] = item;
        listSize++;
    }
    else std::cout << "max capacity" << std::endl;
}

template<typename E>
E ArrayList<E>::remove() {
    if (listSize > 0) {
        E& tmp = listArray[curr];
        for (int i = curr; i < listSize - 1; ++i) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return tmp;
    }
    else {
        std::cout << "min capacity" << std::endl;
        return NULL;

    }
}

template<typename E>
void ArrayList<E>::moveToStart() {
    curr = 0;
}

template<typename E>
void ArrayList<E>::moveToEnd() {
    curr = listSize;
}

template<typename E>
void ArrayList<E>::moveToPos(int pos) {
    if (pos >= 0 && pos <= listSize) curr = pos;
    else std::cout << "index out of range" << std::endl;
}

template<typename E>
void ArrayList<E>::prev() {
    if (curr > 0) curr--;
    else std::cout << "index up to start" << std::endl;
}

template<typename E>
void ArrayList<E>::next() {
    if (curr < listSize) curr++;
    else std::cout << "index up to end" << std::endl;
}

template<typename E>
int ArrayList<E>::currPos() const {
    return curr;
}

template<typename E>
int ArrayList<E>::length() const {
    return listSize;
}

template<typename E>
const E& ArrayList<E>::getValue() const {
    if (curr != listSize) return listArray[curr];
    else {
        std::cout << "no value" << std::endl;
        return NULL;
    }
}

template<typename E>
void ArrayList<E>::show() {
    std::cout << "ArrayList[";
    for (int i = 0; i < listSize; ++i) {
        std::cout << listArray[i] << ", ";
    }
    std::cout << "]";
}