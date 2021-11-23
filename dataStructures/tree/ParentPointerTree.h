/**
 *  Parent Pointer Tree ��ָ���ʾ��
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
            // �ϲ�
            parent_list[find_root(index_a)] = find_root(index_b);
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
        for (int i = 0; i < size; ++i) std::cout << data_list[i] << " ";
        std::cout << "\n�±꣺";
        for (int i = 0; i < size; ++i) std::cout << i << " ";
        std::cout << "\n���ף�";
        for (int i = 0; i < size; ++i) std::cout << parent_list[i] << " ";
    }
};


#endif //ALGORITHM_PARENTPOINTERTREE_H
