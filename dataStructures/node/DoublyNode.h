#ifndef ALGORITHM_DOUBLYNODE_H
#define ALGORITHM_DOUBLYNODE_H

#include <cstddef>
#include <iostream>

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
//        std::cout << "Node::new()"<< freeList->data << std::endl;//test
        DoublyNode<E>* tmp = freeList;
        freeList = freeList->next;
        return tmp;
    }

    void operator delete(void* ptr) {
//        std::cout << "Node::delete()"<< ((DoublyNode<E>*)ptr)->data << std::endl;//test
        ((DoublyNode<E>*)ptr)->next = freeList;
        freeList = (DoublyNode<E>*)ptr;
    }
    //test
//    static void poolShow() {
//        DoublyNode<E>* tmp = freeList;
//        std::cout << "Pool[";
//        while (tmp != nullptr) {
//            std::cout << tmp->data << ", ";
//            tmp = tmp->next;
//        }
//        std::cout << "]" << std::endl;
//    };
};

template<typename E>
DoublyNode<E>* DoublyNode<E>::freeList = nullptr;

#endif //ALGORITHM_DOUBLYNODE_H