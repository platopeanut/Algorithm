/**
 * 区分叶节点和分支节点
 */

#ifndef ALGORITHM_LEAF_AND_INTL_1_H
#define ALGORITHM_LEAF_AND_INTL_1_H

#include <iostream>

class VarBinNode {
public:
    virtual ~VarBinNode() = default;
    virtual bool isLeaf() = 0;
};

template<typename E>
class LeafNode: public VarBinNode {
private:
    E value;
public:
    explicit LeafNode(const E& value): value(value) {}
    bool isLeaf() override {return true;}
    E getValue() {return value;}
};

template<typename E>
class IntlNode: public VarBinNode {
private:
    VarBinNode* left;
    VarBinNode* right;
    E value;
public:
    IntlNode(const E& value, VarBinNode* left, VarBinNode* right)
    : value(value), left(left), right(right) {}
    bool isLeaf() override {return false;}
    VarBinNode* leftChild() {return left;}
    VarBinNode* rightChild() {return right;}
    E getValue() {return value;}

};

template<typename Intl, typename Leaf>
void traverse(VarBinNode* root) {
    if (root == nullptr) return;
    if (root->isLeaf()) std::cout << "Leaf: " << ((LeafNode<Leaf>*) root)->getValue() << std::endl;
    else {
        std::cout << "Internal: " << ((IntlNode<Intl>*) root)->getValue() << std::endl;
        traverse<Intl, Leaf>(((IntlNode<Intl>*)root)->leftChild());
        traverse<Intl, Leaf>(((IntlNode<Intl>*)root)->rightChild());
    }
}


#endif //ALGORITHM_LEAF_AND_INTL_1_H

// 测试代码：4x(2x+a)-c表达式树

//#include "./dataStructures/bin_node/leaf_and_intl_1.h"
//#include <string>
//
//int main()
//{
//    auto* root = new IntlNode<std::string>
//            ("-",
//             new IntlNode<std::string>
//                     ("*",
//                      new IntlNode<std::string>
//                              ("*",
//                               new LeafNode<std::string>("4"),
//                               new LeafNode<std::string>("x")
//                              ),
//                      new IntlNode<std::string>
//                              ("+",
//                               new IntlNode<std::string>
//                                       ("*",
//                                        new LeafNode<std::string>("2"),
//                                        new LeafNode<std::string>("x")
//                                       ),
//                               new LeafNode<std::string>("a")
//                              )
//                     ),
//             new LeafNode<std::string>("c")
//            );
//    traverse<std::string, std::string>(root);
//
//}