#include "./dataStructures/bin_node/BinNode.h"
#include "./dataStructures/bin_node/BSTNode.h"
#include "./dataStructures/bin_node/tool.h"
#include <iostream>
int main()
{
    // �˶���������ѭBST����
    BinNode<char>* root = new BSTNode<int, char>(0, 'A');
    root->setLeft(new BSTNode<int, char>(1, 'B'));
    root->setRight(new BSTNode<int, char>(2, 'C'));
    root->left()->setRight(new BSTNode<int, char>(3, 'D'));
    root->right()->setLeft(new BSTNode<int, char>(4, 'E'));
    root->right()->setRight(new BSTNode<int, char>(5, 'F'));
    root->right()->left()->setLeft(new BSTNode<int, char>(6, 'G'));
    root->right()->right()->setLeft(new BSTNode<int, char>(7, 'H'));
    root->right()->right()->setRight(new BSTNode<int, char>(8, 'I'));
    // ǰ�����
    std::cout << "ǰ�������" << std::endl;
    preorder(root);
    // �������
    std::cout << "\n���������" << std::endl;
    inorder(root);
    // �������
    std::cout << "\n���������" << std::endl;
    postorder(root);
}