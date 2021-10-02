#include "./BinNode.h"
#include <iostream>


// 访问者模式：为树类提供一个通用的遍历函数，把访问处理函数作为遍历函数的一个参数或者一个模板参数

// 前序遍历
template<typename E>
void preorder(BinNode<E>* root) {
    if (root == nullptr) return;
    std::cout << root->element() << std::endl;// 其中这里可以换成处理函数handler
    preorder(root->left());
    preorder(root->right());
}
// 后序遍历
template<typename E>
void postorder(BinNode<E>* root) {
    if (root == nullptr) return;
    preorder(root->left());
    preorder(root->right());
    std::cout << root->element() << std::endl;
}
// 中序遍历
template<typename E>
void inorder(BinNode<E>* root) {
    if (root == nullptr) return;
    preorder(root->left());
    std::cout << root->element() << std::endl;
    preorder(root->right());
}

// 计算二叉树节点数目
template<typename E>
int count(BinNode<E>* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->left()) + count(root->right());
}
// 二叉检索树
//template<typename Key, typename E>
//bool checkBST() {}


