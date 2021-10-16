#ifndef ALGORITHM_GTNODE_H
#define ALGORITHM_GTNODE_H

// General Tree Node
template<typename E>
class GTNode {
public:
    E getValue();
    void setValue(E&);
    bool isLeaf();
    GTNode* getParent();
    GTNode* getLeftMostChild();
    GTNode* getRightSibling();
    void insertFirst(GTNode<E>*);
    void insertNext(GTNode<E>*);
    void removeFirst();
    void removeNext();
};


#endif //ALGORITHM_GTNODE_H
