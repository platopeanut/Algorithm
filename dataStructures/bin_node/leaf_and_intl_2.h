/**
 * 区分叶节点和分支节点
 * 第二种解决方案：复合设计模式
 */

#ifndef ALGORITHM_LEAF_AND_INTL_2_H
#define ALGORITHM_LEAF_AND_INTL_2_H

#include <iostream>

class VarBinNode {
public:
    virtual ~VarBinNode() = default;
    virtual bool isLeaf() = 0;
    virtual void traverse() = 0;
};

template<typename E>
class LeafNode: public VarBinNode {
private:
    E value;
public:
    explicit LeafNode(const E& value): value(value) {}

    bool isLeaf() override {return true;}

    E getValue() {return value;}

    void traverse() override {std::cout << "Leaf: " << getValue() << std::endl;}
};

template<typename E>
class IntlNode: public VarBinNode {
private:
    VarBinNode* lc;
    VarBinNode* rc;
    E value;
public:
    IntlNode(const E& value, VarBinNode* lc, VarBinNode* rc)
        :value(value), lc(lc), rc(rc) {}
    bool isLeaf() override {return false;}
    VarBinNode* getLeft() {return lc;}
    VarBinNode* getRight() {return rc;}
    E getValue() {return value;}
    void traverse() override {
        std::cout << "Internal: " << getValue() << std::endl;
        if (getLeft() != nullptr) getLeft()->traverse();
        if (getRight() != nullptr) getRight()->traverse();
    }
};

void traverse(VarBinNode* root) {if (root != nullptr) root->traverse();}

#endif //ALGORITHM_LEAF_AND_INTL_2_H


// 测试代码：4x(2x+a)-c表达式树

//#include "./dataStructures/bin_node/leaf_and_intl_2.h"
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
//    traverse(root);
//}