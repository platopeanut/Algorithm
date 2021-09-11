#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H

template <typename E>
class Node {
public:
    E data;
    Node<E>* next;
    Node(const E& data, Node<E>* next = NULL) : data(data), next(next) {}
    Node(Node<E>* next = NULL): next(next) {}
};


#endif //ALGORITHM_NODE_H
