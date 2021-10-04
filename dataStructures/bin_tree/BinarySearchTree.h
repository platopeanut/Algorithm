#ifndef ALGORITHM_BINARYSEARCHTREE_H
#define ALGORITHM_BINARYSEARCHTREE_H

#include "../dictionary/Dictionary.h"
#include "../bin_node/BSTNode.h"

template<typename K, typename V>
class BinarySearchTree: public Dictionary<K, V> {
private:
    BSTNode<K, V>* root;
    int nodeCount;
    // private helper functions ��������
    void clearHelp(BSTNode<K, V>*);
    BSTNode<K, V>* insertHelp(BSTNode<K, V>*, const K&, const V&);
    BSTNode<K, V>* removeHelp(BSTNode<K, V>*, const K&);
    V findHelp(BSTNode<K, V>*, const K&) const;
    void printHelp(BSTNode<K, V>*, int) const;
    BSTNode<K, V>* deleteMin(BSTNode<K, V>*);
    BSTNode<K, V>* getMin(BSTNode<K, V>*);

    // ��ȡ��ȸ�������
    void depthHelp(BSTNode<K, V>* node, int* depth, int level = 0) const;

public:
    BinarySearchTree():root(nullptr), nodeCount(0) {}
    ~BinarySearchTree() { clearHelp(root); }

    virtual void clear() { clearHelp(root); root = nullptr; nodeCount = 0; };

    virtual void insert(const K &k, const V &v);

    virtual V remove(const K &k);

    virtual V removeAny();

    virtual V find(const K &k) const;

    virtual int size();

    void print() const;

    // ��ȡ���
    int getDepth() const;
};

#endif //ALGORITHM_BINARYSEARCHTREE_H
