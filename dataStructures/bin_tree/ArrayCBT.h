/**
 * 数组实现完全二叉树
 * CBT: Complete Binary Tree
 */

#ifndef ALGORITHM_ARRAYCBT_H
#define ALGORITHM_ARRAYCBT_H

#include <iostream>

template<typename E>
class ArrayCBT {
private:
    E* list;
    int size;
    int curr;
public:
    ArrayCBT(E* list, int size): list(list), size(size), curr(0){}
    E getValue() {return list[curr];}
    void setValue(const E& value) {list[curr] = value;}
    bool moveToRoot() {
        if (size > 0) {
            curr = 0;
            return true;
        } else return false;
    }
    bool moveToParent() {
        if (curr != 0) {
            curr = (curr - 1) / 2;
            return true;
        } else return false;
    }
    bool moveToLeftChild() {
        if (2*curr+1<size) {
            curr = curr*2+1;
            return true;
        } else return false;
    }
    bool moveToRightChild() {
        if (2*curr+2<size) {
            curr = curr*2+2;
            return true;
        } else return false;
    }
    bool moveToLeftSibling() {
        if (curr%2==0 && curr > 0) {
            curr--;
            return true;
        } else return false;
    }
    bool moveToRightSibling() {
        if (curr%2!=0 && curr+1<size) {
            curr++;
            return true;
        } else return false;
    }
    // 以当前位置作为root开始遍历
    void preorder() {
        std::cout << getValue() << " ";
        if (moveToLeftChild()) {
            preorder();
            moveToParent();
        }
        if (moveToRightChild()) {
            preorder();
            moveToParent();
        }

    }
};


#endif //ALGORITHM_ARRAYCBT_H




// 测试
//#include "./dataStructures/bin_tree/ArrayCBT.h"
//
//int main()
//{
//    int list[] = {1,2,3,4,5,6,7,8,9};
//    auto* cbt = new ArrayCBT<int>(list, sizeof(list)/ sizeof(list[0]));
//    cbt->preorder();
//}

