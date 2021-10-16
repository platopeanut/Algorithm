#include "ArrayList.h"
#include <iostream>
#include "../../util/StringException.h"

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
    } else throw StringException("ArrayList::insert()==>max capacity");
}

template<typename E>
void ArrayList<E>::append(const E& item) {
    if (listSize < maxSize) {
        listArray[listSize] = item;
        listSize++;
    }
    else throw StringException("ArrayList::append()==>max capacity");
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
    } else throw StringException("ArrayList::remove()==>min capacity");
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
    else throw StringException("ArrayList::moveToPos()==>index out of range");
}

template<typename E>
void ArrayList<E>::prev() {
    if (curr > 0) curr--;
    else throw StringException("ArrayList::prev()==>index up to start");
}

template<typename E>
void ArrayList<E>::next() {
    if (curr < listSize) curr++;
    else throw StringException("ArrayList::next()==>index up to end");
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
    else throw StringException("ArrayList::getValue()==>No value");
}

template<typename E>
void ArrayList<E>::show() {
    std::cout << "ArrayList[";
    for (int i = 0; i < listSize; ++i) {
        std::cout << listArray[i] << ", ";
    }
    std::cout << "]";
}

template<typename E>
void ArrayList<E>::setValue(const E &item) {
    if (curr >= 0 && curr < listSize) {
        listArray[curr] = item;
    } else throw StringException("ArrayList::setValue()==>No getElement");
}
