#ifndef ALGORITHM_GTREE_H
#define ALGORITHM_GTREE_H

#include "./GTNode.h"

// General Tree ADT
template<typename E>
class GTree {
public:
    void clear();
    GTNode<E>* getRoot();
    void newRoot(E&, GTNode<E>*);
    void print();
};


#endif //ALGORITHM_GTREE_H
