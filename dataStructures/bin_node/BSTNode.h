#ifndef ALGORITHM_BSTNODE_H
#define ALGORITHM_BSTNODE_H

#include "./BinNode.h"

// Binary Search Tree Node: ¶þ²æ¼ìË÷Ê÷½Úµã
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

    V &element() {return value;}
    void setElement(const V& value) {this->value = value;}

    K& getKey() {return key;}
    void setKey(const K& key) { this->key = key;}

    BSTNode<K, V> *left() const {return lc;}
    void setLeft(BinNode<V> *node) { this->lc = (BSTNode*)node;}

    BSTNode<K, V> *right() const {return rc;}
    void setRight(BinNode<V> *node) {this->rc = (BSTNode*)node;}

    bool isLeaf() {return (this->lc == nullptr)&&(this->rc == nullptr);}
};


#endif //ALGORITHM_BSTNODE_H
