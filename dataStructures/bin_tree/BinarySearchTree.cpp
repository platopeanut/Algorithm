#include "BinarySearchTree.h"
#include <iostream>
#include "../../util/StringException.h"

template<typename K, typename V>
void BinarySearchTree<K, V>::clearHelp(BSTNode<K, V>* node) {
    // 采用后序遍历：左右中
    if (node == nullptr) return;
    clearHelp(node->left());
    clearHelp(node->right());
    delete node;
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::insertHelp(BSTNode<K, V>* node, const K& key, const V& value) {
    if (node == nullptr) return new BSTNode<K, V>(key, value);
    if (node->getKey() > key) node->setLeft(insertHelp(node->left(), key, value));
    else node->setRight(insertHelp(node->right(), key, value));
    return node;
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::removeHelp(BSTNode<K, V>* node, const K& key) {
    if (node == nullptr) throw StringException("BinarySearchTree<K, V>::removeHelp==>Key is not in tree");
    else if (key < node->getKey()) node->setLeft(removeHelp(node->left(), key));
    else if (key > node->getKey()) node->setRight(removeHelp(node->right(), key));
    else {
        BSTNode<K, V>* tmp = node;
        // 分类：按照要删除的节点有0,1,2个子节点
        if (node->left() == nullptr) {
            node = node->right();
            delete tmp;
        } else if (node->right() == nullptr) {
            node = node->left();
            delete tmp;
        } else {
            // 选择右子树最小值与待删除节点进行替换
            auto* min = getMin(node->right());
            tmp->setElement(min->element());
            tmp->setKey(min->getKey());
            // 删除min后右子树重新排列
            tmp->setRight(deleteMin(tmp->right()));
            delete min;
        }
    }
    return node;
}

template<typename K, typename V>
V BinarySearchTree<K, V>::findHelp(BSTNode<K, V>* node, const K& key) const {
    if (node == nullptr) throw StringException("BinarySearchTree<K, V>::findHelp==>Not Found");
    if (node->getKey() > key) return findHelp(node->left(), key);
    if (node->getKey() < key) return findHelp(node->right(), key);
    return node->element();
}

template<typename K, typename V>
void BinarySearchTree<K, V>::printHelp(BSTNode<K, V>* node, int level) const {
    // 中序遍历
    // 缩进表示深度关系
    if (node == nullptr) return;
    printHelp(node->left(), level + 1);
    for (int i = 0; i < level; ++i) std::cout << "  ";
    std::cout << node->getKey() << std::endl;
    printHelp(node->right(), level + 1);
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::deleteMin(BSTNode<K, V>* node) {
    if (node->left() == nullptr) return node->right();
    else {
        node->setLeft(deleteMin(node->left()));
        return node;
    }
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::getMin(BSTNode<K, V>* node) {
    if (node->left() == nullptr) return node;
    else return getMin(node->left());
}

template<typename K, typename V>
void BinarySearchTree<K, V>::insert(const K &k, const V &v) {
    root = insertHelp(root, k, v);
    nodeCount ++;
}

template<typename K, typename V>
V BinarySearchTree<K, V>::remove(const K &k) {
    // 先找再删
    // 找不到findHelp会抛异常
    V value = findHelp(root, k);
    root = removeHelp(root, k);
    nodeCount --;
    return value;
}

template<typename K, typename V>
V BinarySearchTree<K, V>::removeAny() {
    // 每次删除根节点
    if (root != nullptr) {
        V tmp = root->element();
        root = removeHelp(root, root->getKey());
        nodeCount --;
        return tmp;
    } else throw StringException("BinarySearchTree<K, V>::removeAny()==>the BST is empty");
}

template<typename K, typename V>
V BinarySearchTree<K, V>::find(const K &k) const { return findHelp(root, k); } // 找不到findHelp会抛异常

template<typename K, typename V>
int BinarySearchTree<K, V>::size() { return nodeCount; }

template<typename K, typename V>
void BinarySearchTree<K, V>::print() const {
    if (root == nullptr) std::cout << "the BST is empty" << std::endl;
    else printHelp(root, 0);
}

template<typename K, typename V>
void BinarySearchTree<K, V>::depthHelp(BSTNode<K, V> *node, int *depth, int level) const {
    if (node == nullptr) return;
    level ++;
    if (level > *depth) *depth = level;
    depthHelp(node->left(), depth, level);
    depthHelp(node->right(), depth, level);
}

template<typename K, typename V>
int BinarySearchTree<K, V>::getDepth() const {
    int depth = 0;
    depthHelp(root, &depth);
    return depth;
}
