#include "./dataStructures/bin_node/BinNode.h"
#include "./dataStructures/bin_tree/BinarySearchTree.cpp"
#include <iostream>

// ǰ�����
template<typename E>
void preorder(BinNode<E>* node) {
    if (node == nullptr) return;
    std::cout << node->getElement() << " ";
    preorder(node->getLeft());
    preorder(node->getRight());
}

// �������
template<typename E>
void inorder(BinNode<E>* node) {
    if (node == nullptr) return;
    inorder(node->getLeft());
    std::cout << node->getElement() << " ";
    inorder(node->getRight());
}

// �������
template<typename E>
void postorder(BinNode<E>* node) {
    if (node == nullptr) return;
    postorder(node->getLeft());
    postorder(node->getRight());
    std::cout << node->getElement() << " ";
}

int main() {
    auto *tree = new BinarySearchTree<int, int>;
    // ������ڵ�
    int list[] = {15, 20, 25, 18, 16, 5, 7};
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); ++i) tree->insert(list[i], list[i]);
    // ����
    std::cout << "ǰ�������";
    preorder(tree->getRoot());
    std::cout << "\n���������";
    inorder(tree->getRoot());
    std::cout << "\n���������";
    postorder(tree->getRoot());
    return 0;
}