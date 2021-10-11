#ifndef ALGORITHM_LEAFNODE_H
#define ALGORITHM_LEAFNODE_H

#include "./HuffNode.h"

template<typename E>
class LeafNode: public HuffNode {
private:
    E value;
    int weight;
public:
    LeafNode(const E& value, int weight): value(value), weight(weight) {}
    int getWeight() override {return weight;}
    bool isLeaf() override {return true;}
    E getValue() {return value;}
};


#endif //ALGORITHM_LEAFNODE_H
