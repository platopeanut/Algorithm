#ifndef ALGORITHM_HUFFTREE_H
#define ALGORITHM_HUFFTREE_H

#include "../bin_node/HuffNode.h"
#include "../bin_node/LeafNode.h"
#include "../bin_node/IntlNode.h"
#include "../heap/Heap.cpp"
#include <string>

template<typename E>
class HuffTree {
private:
    HuffNode* root;
    void showHelper(HuffNode* node, const std::string& code) {
        if (node->isLeaf()) {
            auto* tmp = (LeafNode<E>*) node;
            std::cout << "{" << tmp->getValue() << ", "
                    << tmp->getWeight() << "} code: "
                    << code << std::endl;
        } else {
            auto* tmp = (IntlNode<E>*) node;
            showHelper(tmp->getLeft(), code+"0");
            showHelper(tmp->getRight(), code + "1");
        }
    }
public:
    HuffTree(E& value, int weight) {root = new LeafNode<E>(value, weight);}
    HuffTree(HuffTree<E>* left, HuffTree<E>* right) {root = new IntlNode<E>(left->getRoot(), right->getRoot());}
    ~HuffTree() = default;
    HuffNode* getRoot() {return root;}
    int getWeight() {return root->getWeight();}

    // show
    void show() {
        showHelper(root, "");
    }

};

template<typename E>
std::ostream & operator << (std::ostream& os, HuffTree<E>* tree) {
    os << tree->getWeight();
    return os;
}

// Huffman树比较器(最小)
template<typename E>
class HuffCompare: public Compare<HuffTree<E>*> {
public:
    bool prior(HuffTree<E>* a, HuffTree<E>* b) override {
        return a->getWeight() < b->getWeight();
    }
};

template<typename E>
HuffTree<E>* buildHuff(HuffTree<E>** treeArray, int count) {
    auto* forest = new Heap<HuffTree<E>*>(treeArray, count, count, new HuffCompare<E>);
    HuffTree<E> *tmp1, *tmp2, *tmp3 = nullptr;
    while (forest->size() > 1) {
        tmp1 = forest->removeFirst();
        tmp2 = forest->removeFirst();
        tmp3 = new HuffTree<E>(tmp1, tmp2);
        forest->insert(tmp3);
        delete tmp1;
        delete tmp2;
    }
    return tmp3;
}
#endif //ALGORITHM_HUFFTREE_H
