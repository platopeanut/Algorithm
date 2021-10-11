#include "./BinNode.h"
#include "./BSTNode.h"
#include <iostream>


// 访问者模式：为树类提供一个通用的遍历函数，把访问处理函数作为遍历函数的一个参数或者一个模板参数

// 前序遍历
template<typename E>
void preorder(BinNode<E>* root) {
    if (root == nullptr) return;
    std::cout << root->element() << " ";// 其中这里可以换成处理函数handler
    preorder(root->left());
    preorder(root->right());
}
// 后序遍历
template<typename E>
void postorder(BinNode<E>* root) {
    if (root == nullptr) return;
    postorder(root->left());
    postorder(root->right());
    std::cout << root->element() << " ";
}
// 中序遍历
template<typename E>
void inorder(BinNode<E>* root) {
    if (root == nullptr) return;
    inorder(root->left());
    std::cout << root->element() << " ";
    inorder(root->right());
}

// 计算二叉树节点数目
template<typename E>
int count(BinNode<E>* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->left()) + count(root->right());
}

// 判断一个树是否为二叉检索树
template<typename E>
bool checkBST(BinNode<E>* root, E low, E high) {
    if (root == nullptr) return true;
    E key = root->element();
    if (key < low || key > high) return false;
    if (!checkBST<E>(root->left(), low, key)) return false;
    return checkBST<E>(root->right(), key, high);
}

// 查询K是否在二叉树中
template<typename E>
bool search(BinNode<E>* root, E key) {
    if (root == nullptr) return false;
    if (root->element() == key) return true;
    return search(root->left(), key) || search(root->right(), key);
}
