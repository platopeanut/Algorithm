#ifndef ALGORITHM_BSTNODE_H
#define ALGORITHM_BSTNODE_H

#include "./BinNode.h"

// Binary Search Tree Node: ???????????ڵ?
template<typename K, typename V>
class BSTNode : public BinNode<V> {
private:
    // key of node
    K key;
    // value of node
    V value;
    // left child
    BSTNode* lc;
    // right child
    BSTNode* rc;
public:
    BSTNode() {lc = rc = nullptr;}
    BSTNode(K key, V value, BSTNode* lc= nullptr, BSTNode* rc = nullptr)
    :key(key), value(value), lc(lc), rc(rc){}
    ~BSTNode() = default;

    V &getElement() {return value;}
    void setElement(const V& v) { this->value = v;}

    K& getKey() {return key;}
    void setKey(const K& k) { this->key = k;}

    BSTNode* getLeft() const {return lc;}
    void setLeft(BinNode<V> *node) { this->lc = (BSTNode*)node;}

    BSTNode* getRight() const {return rc;}
    void setRight(BinNode<V> *node) {this->rc = (BSTNode*)node;}

    bool isLeaf() {return (this->lc == nullptr)&&(this->rc == nullptr);}
};


#endif //ALGORITHM_BSTNODE_H
