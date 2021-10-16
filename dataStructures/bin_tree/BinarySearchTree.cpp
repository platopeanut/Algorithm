#include "BinarySearchTree.h"
#include <iostream>
#include "../../util/StringException.h"

template<typename K, typename V>
void BinarySearchTree<K, V>::clearHelp(BSTNode<K, V>* node) {
    // ���ú��������������
    if (node == nullptr) return;
    clearHelp(node->getLeft());
    clearHelp(node->getRight());
    delete node;
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::insertHelp(BSTNode<K, V>* node, const K& key, const V& value) {
    if (node == nullptr) return new BSTNode<K, V>(key, value);
    if (node->getKey() > key) node->setLeft(insertHelp(node->getLeft(), key, value));
    else node->setRight(insertHelp(node->getRight(), key, value));
    return node;
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::removeHelp(BSTNode<K, V>* node, const K& key) {
    if (node == nullptr) throw StringException("BinarySearchTree<K, V>::removeHelp==>Key is not in tree");
    else if (key < node->getKey()) node->setLeft(removeHelp(node->getLeft(), key));
    else if (key > node->getKey()) node->setRight(removeHelp(node->getRight(), key));
    else {
        BSTNode<K, V>* tmp = node;
        // ���ࣺ����Ҫɾ���Ľڵ���0,1,2���ӽڵ�
        if (node->getLeft() == nullptr) {
            node = node->getRight();
            delete tmp;
        } else if (node->getRight() == nullptr) {
            node = node->getLeft();
            delete tmp;
        } else {
            // ѡ����������Сֵ���ɾ���ڵ�����滻
            auto* min = getMin(node->getRight());
            tmp->setElement(min->getElement());
            tmp->setKey(min->getKey());
            // ɾ��min����������������
            tmp->setRight(deleteMin(tmp->getRight()));
            delete min;
        }
    }
    return node;
}

template<typename K, typename V>
V BinarySearchTree<K, V>::findHelp(BSTNode<K, V>* node, const K& key) const {
    if (node == nullptr) throw StringException("BinarySearchTree<K, V>::findHelp==>Not Found");
    if (node->getKey() > key) return findHelp(node->getLeft(), key);
    if (node->getKey() < key) return findHelp(node->getRight(), key);
    return node->getElement();
}

template<typename K, typename V>
void BinarySearchTree<K, V>::printHelp(BSTNode<K, V>* node, int level) const {
    // �������
    // ������ʾ��ȹ�ϵ
    if (node == nullptr) return;
    printHelp(node->getLeft(), level + 1);
    for (int i = 0; i < level; ++i) std::cout << "  ";
    std::cout << node->getKey() << std::endl;
    printHelp(node->getRight(), level + 1);
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::deleteMin(BSTNode<K, V>* node) {
    if (node->getLeft() == nullptr) return node->getRight();
    else {
        node->setLeft(deleteMin(node->getLeft()));
        return node;
    }
}

template<typename K, typename V>
BSTNode<K, V> *BinarySearchTree<K, V>::getMin(BSTNode<K, V>* node) {
    if (node->getLeft() == nullptr) return node;
    else return getMin(node->getLeft());
}

template<typename K, typename V>
void BinarySearchTree<K, V>::insert(const K &k, const V &v) {
    root = insertHelp(root, k, v);
    nodeCount ++;
}

template<typename K, typename V>
V BinarySearchTree<K, V>::remove(const K &k) {
    // ������ɾ
    // �Ҳ���findHelp�����쳣
    V value = findHelp(root, k);
    root = removeHelp(root, k);
    nodeCount --;
    return value;
}

template<typename K, typename V>
V BinarySearchTree<K, V>::removeAny() {
    // ÿ��ɾ�����ڵ�
    if (root != nullptr) {
        V tmp = root->getElement();
        root = removeHelp(root, root->getKey());
        nodeCount --;
        return tmp;
    } else throw StringException("BinarySearchTree<K, V>::removeAny()==>the BST is empty");
}

template<typename K, typename V>
V BinarySearchTree<K, V>::find(const K &k) const { return findHelp(root, k); } // �Ҳ���findHelp�����쳣

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
    depthHelp(node->getLeft(), depth, level);
    depthHelp(node->getRight(), depth, level);
}

template<typename K, typename V>
int BinarySearchTree<K, V>::getDepth() const {
    int depth = 0;
    depthHelp(root, &depth);
    return depth;
}
