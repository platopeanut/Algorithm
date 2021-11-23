/**
 *  Parent Pointer Tree 父指针表示法
 */

#ifndef ALGORITHM_PARENTPOINTERTREE_H
#define ALGORITHM_PARENTPOINTERTREE_H

#include "./ParPtrPair.h"
#include <iostream>

template<typename T>
class ParentPointerTree {
private:
    T* data_list;
    int* parent_list;
    int size;
public:
    ParentPointerTree(const T* data_list, int size):size(size) {
        this->data_list = new T[size];
        for (int i = 0; i < size; ++i) this->data_list[i] = data_list[i];
        this->parent_list = new int[size];
        for (int i = 0; i < size; ++i) this->parent_list[i] = -1;
    }
    ~ParentPointerTree() {
        delete[] data_list;
        delete[] parent_list;
    }
    void build(ParPtrPair<T>* pairs) {
        T a, b;
        while (pairs->getPair(&a, &b)) {
            int index_a = get_index(a);
            int index_b = get_index(b);
            // 合并
            parent_list[find_root(index_a)] = find_root(index_b);
        }
    }
    // 获取数据的下标，没有则返回size
    int get_index(const T data) {
        int i;
        for (i = 0; i < size; ++i)
            if (data == data_list[i]) return i;
        return i;
    }
    // 找curr结点的根节点，无任何优化
    int find_root(int curr) {
        while (parent_list[curr] != -1)
            curr = parent_list[curr];
        return curr;
    }

    void show() {
        std::cout << "数据：";
        for (int i = 0; i < size; ++i) std::cout << data_list[i] << " ";
        std::cout << "\n下标：";
        for (int i = 0; i < size; ++i) std::cout << i << " ";
        std::cout << "\n父亲：";
        for (int i = 0; i < size; ++i) std::cout << parent_list[i] << " ";
    }
};


#endif //ALGORITHM_PARENTPOINTERTREE_H
