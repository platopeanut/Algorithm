#ifndef ALGORITHM_HUFFNODE_H
#define ALGORITHM_HUFFNODE_H

class HuffNode {
public:
    virtual ~HuffNode() {}
    virtual int getWeight() = 0;
    virtual bool isLeaf() = 0;
};
#endif //ALGORITHM_HUFFNODE_H
