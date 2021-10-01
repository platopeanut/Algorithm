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

    V &element() override {return value;}
    void setElement(const V& value) override {this->value = value;}

    K& getKey() {return key;}
    void setKey(const K& key) { this->key = key;}

    BinNode<V> *left() const override {return lc;}
    void setLeft(BinNode *node) override { this->lc = (BSTNode*)node;}

    BinNode<V> *right() const override {return rc;}
    void setRight(BinNode *node) override {this->rc = (BSTNode*)node;}

    bool isLeaf() override {return (this->lc == nullptr)&&(this->rc == nullptr);}
};


#endif //ALGORITHM_BSTNODE_H
