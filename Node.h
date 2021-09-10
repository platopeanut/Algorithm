#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H

template <typename E>
class Node {
public:
    E data;
    Node<E>* next;
    Node(E data, Node<E>* next) : data(data), next(next) {}
    Node(Node<E>* next): next(next) {}
};


#endif //ALGORITHM_NODE_H
