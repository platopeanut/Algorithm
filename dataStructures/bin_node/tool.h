#include "./BinNode.h"
#include "./BSTNode.h"
#include <iostream>


// 访问者模式：为树类提供一个通用的遍历函数，把访问处理函数作为遍历函数的一个参数或者一个模板参数

// 前序遍历
template<typename E>
void preorder(BinNode<E>* root) {
    if (root == nullptr) return;
    std::cout << root->getElement() << " ";// 其中这里可以换成处理函数handler
    preorder(root->getLeft());
    preorder(root->getRight());
}
// 后序遍历
template<typename E>
void postorder(BinNode<E>* root) {
    if (root == nullptr) return;
    postorder(root->getLeft());
    postorder(root->getRight());
    std::cout << root->getElement() << " ";
}
// 中序遍历
template<typename E>
void inorder(BinNode<E>* root) {
    if (root == nullptr) return;
    inorder(root->getLeft());
    std::cout << root->getElement() << " ";
    inorder(root->getRight());
}

// 计算二叉树节点数目
template<typename E>
int count(BinNode<E>* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->getLeft()) + count(root->getRight());
}

// 判断一个树是否为二叉检索树
template<typename E>
bool checkBST(BinNode<E>* root, E low, E high) {
    if (root == nullptr) return true;
    E key = root->getElement();
    if (key < low || key > high) return false;
    if (!checkBST<E>(root->getLeft(), low, key)) return false;
    return checkBST<E>(root->getRight(), key, high);
}

// 查询K是否在二叉树中
template<typename E>
bool search(BinNode<E>* root, E key) {
    if (root == nullptr) return false;
    if (root->getElement() == key) return true;
    return search(root->getLeft(), key) || search(root->getRight(), key);
}
