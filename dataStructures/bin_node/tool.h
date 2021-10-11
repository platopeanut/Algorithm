#include "./BinNode.h"
#include "./BSTNode.h"
#include <iostream>


// ������ģʽ��Ϊ�����ṩһ��ͨ�õı����������ѷ��ʴ�������Ϊ����������һ����������һ��ģ�����

// ǰ�����
template<typename E>
void preorder(BinNode<E>* root) {
    if (root == nullptr) return;
    std::cout << root->element() << " ";// ����������Ի��ɴ�����handler
    preorder(root->left());
    preorder(root->right());
}
// �������
template<typename E>
void postorder(BinNode<E>* root) {
    if (root == nullptr) return;
    postorder(root->left());
    postorder(root->right());
    std::cout << root->element() << " ";
}
// �������
template<typename E>
void inorder(BinNode<E>* root) {
    if (root == nullptr) return;
    inorder(root->left());
    std::cout << root->element() << " ";
    inorder(root->right());
}

// ����������ڵ���Ŀ
template<typename E>
int count(BinNode<E>* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->left()) + count(root->right());
}

// �ж�һ�����Ƿ�Ϊ���������
template<typename E>
bool checkBST(BinNode<E>* root, E low, E high) {
    if (root == nullptr) return true;
    E key = root->element();
    if (key < low || key > high) return false;
    if (!checkBST<E>(root->left(), low, key)) return false;
    return checkBST<E>(root->right(), key, high);
}

// ��ѯK�Ƿ��ڶ�������
template<typename E>
bool search(BinNode<E>* root, E key) {
    if (root == nullptr) return false;
    if (root->element() == key) return true;
    return search(root->left(), key) || search(root->right(), key);
}
