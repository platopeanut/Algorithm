#ifndef ALGORITHM_DOUBLYNODE_H
#define ALGORITHM_DOUBLYNODE_H

template<typename E>
class DoublyNode {
private:
    static DoublyNode<E>* freeList;
public:
    DoublyNode<E>* prev;
    DoublyNode<E>* next;
    E data;
    DoublyNode(const E& data, DoublyNode<E>* prev, DoublyNode<E>* next):data(data), prev(prev), next(next) {}
    DoublyNode(DoublyNode<E>* prev = nullptr, DoublyNode<E>* next = nullptr): prev(prev), next(next) {}

    void* operator new(size_t) {
        if (freeList == nullptr) return ::new DoublyNode<E>;
        DoublyNode<E>* tmp = freeList;
        freeList = freeList->next;
        return tmp;
    }

    void operator delete(void* ptr) {
        ptr = (DoublyNode<E>*)ptr;
        ptr->next = freeList;
        freeList = ptr;
    }
};

template<typename E>
DoublyNode<E>* DoublyNode<E>::freeList = nullptr;

#endif //ALGORITHM_DOUBLYNODE_H