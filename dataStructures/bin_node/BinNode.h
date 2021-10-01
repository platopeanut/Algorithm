#ifndef ALGORITHM_BINNODE_H
#define ALGORITHM_BINNODE_H

template<typename E>
class BinNode {
public:
    virtual ~BinNode() {}
    // 获取二叉树节点值
    virtual E& element() = 0;
    // 设置值
    virtual void setElement(const E&) = 0;
    // 获取左子树节点
    virtual BinNode* left() const = 0;
    // 设置左子树节点
    virtual void setLeft(BinNode*) = 0;
    // 获取右子树节点
    virtual BinNode* right() const = 0;
    // 设置右子树节点
    virtual void setRight(BinNode*) = 0;
    // 判断是否为叶节点
    virtual bool isLeaf() = 0;
};


#endif //ALGORITHM_BINNODE_H
