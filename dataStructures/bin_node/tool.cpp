#include "./BinNode.h"
#include <iostream>
// ǰ�����
template<typename E>
void preorder(BinNode<E>* root) {
    if (root == nullptr) return;
    std::cout << root->element() << std::endl;// ����������Ի��ɴ�����handler
    preorder(root->left());
    preorder(root->right());
}
// �������
template<typename E>
void postorder(BinNode<E>* root) {
    if (root == nullptr) return;
    preorder(root->left());
    preorder(root->right());
    std::cout << root->element() << std::endl;
}
// �������
template<typename E>
void inorder(BinNode<E>* root) {
    if (root == nullptr) return;
    preorder(root->left());
    std::cout << root->element() << std::endl;
    preorder(root->right());
}

// ����������ڵ���Ŀ
template<typename E>
int count(BinNode<E>* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->left()) + count(root->right());
}
// ���������
//template<typename Key, typename E>
//bool checkBST() {}


