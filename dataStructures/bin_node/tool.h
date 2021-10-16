#include "./BinNode.h"
#include "./BSTNode.h"
#include <iostream>


// ������ģʽ��Ϊ�����ṩһ��ͨ�õı����������ѷ��ʴ�������Ϊ����������һ����������һ��ģ�����

// ǰ�����
template<typename E>
void preorder(BinNode<E>* root) {
    if (root == nullptr) return;
    std::cout << root->getElement() << " ";// ����������Ի��ɴ�����handler
    preorder(root->getLeft());
    preorder(root->getRight());
}
// �������
template<typename E>
void postorder(BinNode<E>* root) {
    if (root == nullptr) return;
    postorder(root->getLeft());
    postorder(root->getRight());
    std::cout << root->getElement() << " ";
}
// �������
template<typename E>
void inorder(BinNode<E>* root) {
    if (root == nullptr) return;
    inorder(root->getLeft());
    std::cout << root->getElement() << " ";
    inorder(root->getRight());
}

// ����������ڵ���Ŀ
template<typename E>
int count(BinNode<E>* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->getLeft()) + count(root->getRight());
}

// �ж�һ�����Ƿ�Ϊ���������
template<typename E>
bool checkBST(BinNode<E>* root, E low, E high) {
    if (root == nullptr) return true;
    E key = root->getElement();
    if (key < low || key > high) return false;
    if (!checkBST<E>(root->getLeft(), low, key)) return false;
    return checkBST<E>(root->getRight(), key, high);
}

// ��ѯK�Ƿ��ڶ�������
template<typename E>
bool search(BinNode<E>* root, E key) {
    if (root == nullptr) return false;
    if (root->getElement() == key) return true;
    return search(root->getLeft(), key) || search(root->getRight(), key);
}
