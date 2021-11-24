/**
 *  Parent Pointer Tree 父指针表示法
 */

#ifndef ALGORITHM_PARPTRTREE_H
#define ALGORITHM_PARPTRTREE_H

#include "./ParPtrPairs.h"
#include <iostream>

template<typename T>
class ParPtrTree {
private:
    T* data_list;
    int* parent_list;
    int size;
public:
    ParPtrTree(const T* data_list, int size): size(size) {
        this->data_list = new T[size];
        for (int i = 0; i < size; ++i) this->data_list[i] = data_list[i];
        this->parent_list = new int[size];
        for (int i = 0; i < size; ++i) this->parent_list[i] = -1;
    }
    ParPtrTree(int size): size(size) {
        this->data_list = new T[size];
        for (int i = 0; i < size; ++i) this->data_list[i] = i;
        this->parent_list = new int[size];
        for (int i = 0; i < size; ++i) this->parent_list[i] = -1;
    }
    ~ParPtrTree() {
        delete[] data_list;
        delete[] parent_list;
    }
    // build 所有pair
    void build(ParPtrPairs<T>* pairs) {
        T a, b;
        while (pairs->getPair(&a, &b)) {
            int index_a = get_index(a);
            int index_b = get_index(b);
            // 合并
            int root_a = find_root(index_a);
            int root_b = find_root(index_b);
            if (root_a != root_b) {
                parent_list[root_a] = root_b;
            }
        }
    }
    // build 单个, 若重复合并则返回false
    bool build(T a, T b) {
        int index_a = get_index(a);
        int index_b = get_index(b);
        // 合并
        int root_a = find_root(index_a);
        int root_b = find_root(index_b);
        if (root_a != root_b) {
            parent_list[root_a] = root_b;
            return true;
        } else {
            return false;
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
        for (int i = 0; i < size; ++i) std::cout << data_list[i] << "\t";
        std::cout << "\n下标：";
        for (int i = 0; i < size; ++i) std::cout << i << "\t";
        std::cout << "\n父亲：";
        for (int i = 0; i < size; ++i) std::cout << parent_list[i] << "\t";
    }
};


#endif //ALGORITHM_PARPTRTREE_H
