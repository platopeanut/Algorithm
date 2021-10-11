#ifndef ALGORITHM_HUFFTREE_H
#define ALGORITHM_HUFFTREE_H

#include "../bin_node/HuffNode.h"
#include "../bin_node/LeafNode.h"
#include "../bin_node/IntlNode.h"

template<typename E>
class HuffTree {
private:
    HuffNode* root;
public:
    HuffTree(E& value, int weight) {root = new LeafNode<E>(value, weight);}
    HuffTree(HuffTree<E>* left, HuffTree<E>* right) {root = new IntlNode<E>(left->getRoot(), right->getRoot());}
    ~HuffTree() {}
    HuffNode* getRoot() {return root;}
    int getWeight() {return root->getWeight();}
};
#endif //ALGORITHM_HUFFTREE_H
