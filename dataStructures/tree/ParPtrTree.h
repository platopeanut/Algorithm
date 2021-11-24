/**
 *  Parent Pointer Tree ��ָ���ʾ��
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
    // build ����pair
    void build(ParPtrPairs<T>* pairs) {
        T a, b;
        while (pairs->getPair(&a, &b)) {
            int index_a = get_index(a);
            int index_b = get_index(b);
            // �ϲ�
            int root_a = find_root(index_a);
            int root_b = find_root(index_b);
            if (root_a != root_b) {
                parent_list[root_a] = root_b;
            }
        }
    }
    // build ����, ���ظ��ϲ��򷵻�false
    bool build(T a, T b) {
        int index_a = get_index(a);
        int index_b = get_index(b);
        // �ϲ�
        int root_a = find_root(index_a);
        int root_b = find_root(index_b);
        if (root_a != root_b) {
            parent_list[root_a] = root_b;
            return true;
        } else {
            return false;
        }
    }
    // ��ȡ���ݵ��±꣬û���򷵻�size
    int get_index(const T data) {
        int i;
        for (i = 0; i < size; ++i)
            if (data == data_list[i]) return i;
        return i;
    }
    // ��curr���ĸ��ڵ㣬���κ��Ż�
    int find_root(int curr) {
        while (parent_list[curr] != -1)
            curr = parent_list[curr];
        return curr;
    }

    void show() {
        std::cout << "���ݣ�";
        for (int i = 0; i < size; ++i) std::cout << data_list[i] << "\t";
        std::cout << "\n�±꣺";
        for (int i = 0; i < size; ++i) std::cout << i << "\t";
        std::cout << "\n���ף�";
        for (int i = 0; i < size; ++i) std::cout << parent_list[i] << "\t";
    }
};


#endif //ALGORITHM_PARPTRTREE_H
