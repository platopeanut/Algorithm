#ifndef ALGORITHM_INTLNODE_H
#define ALGORITHM_INTLNODE_H

#include "./HuffNode.h"

template<typename E>
class IntlNode: public HuffNode {
private:
    HuffNode* leftChild;
    HuffNode* rightChild;
    int weight;
public:
    IntlNode(HuffNode* leftChild, HuffNode* rightChild)
    :weight(leftChild->getWeight()+rightChild->getWeight()),
    leftChild(leftChild), rightChild(rightChild) {}
    int getWeight() override {return weight;}
    bool isLeaf() override {return false;}
    HuffNode* getLeft() const {return leftChild;}
    void setLeft(HuffNode* left) {leftChild = (IntlNode<E>*) left;}
    HuffNode* getRight() const {return rightChild;}
    void setRight(HuffNode* right) {rightChild = (IntlNode<E>*) right;}
};


#endif //ALGORITHM_INTLNODE_H
