#ifndef ALGORITHM_BINNODE_H
#define ALGORITHM_BINNODE_H

template<typename E>
class BinNode {
public:
    virtual ~BinNode() {}
    // ��ȡ�������ڵ�ֵ
    virtual E& element() = 0;
    // ����ֵ
    virtual void setElement(const E&) = 0;
    // ��ȡ�������ڵ�
    virtual BinNode* left() const = 0;
    // �����������ڵ�
    virtual void setLeft(BinNode*) = 0;
    // ��ȡ�������ڵ�
    virtual BinNode* right() const = 0;
    // �����������ڵ�
    virtual void setRight(BinNode*) = 0;
    // �ж��Ƿ�ΪҶ�ڵ�
    virtual bool isLeaf() = 0;
};


#endif //ALGORITHM_BINNODE_H
