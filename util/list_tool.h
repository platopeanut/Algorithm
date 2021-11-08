/**
 *  list��صĴ�������������
 */

#ifndef ALGORITHM_LIST_TOOL_H
#define ALGORITHM_LIST_TOOL_H

#include <ctime>
#include <random>
#include <iostream>
#include "./StringException.h"
#include "../dataStructures/node/Node.h"


// ��ȡһ��size������������飬��Χ��lo..hi
int* get_randomInt_list(int size, int lo, int hi) {
    srand(unsigned (time(nullptr)));
    int* result = new int[size];
    for (int i = 0; i < size; ++i) result[i] = rand() % (hi - lo) + lo;
    return result;
}
// ��ȡ
int* get_range_list(int start, int stop, int step = 1, int* size = nullptr) {
    int num = (stop - start) / step;
    if (size != nullptr) *size = num;
    int* list = new int[num];
    for (int i = start, index = 0; i != stop; i += step) list[index++] = i;
    return list;
}

// ��ӡlist
template<typename E>
void list_show(E* list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// ��ӡvector
template<typename E>
void vector_show(std::vector<E>& list) {
    std::cout << "vector[";
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// ����list��indexΪa��b������Ԫ��
template<typename E>
void swap(E* list, int a, int b) {
    E tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

//��������
template<typename E>
void shuffle(E* list, int size) {
    srand(unsigned(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        int index = rand() % (size - i) + i;
        if (index != i) {
            auto tmp = list[index];
            list[index] = list[i];
            list[i] = tmp;
        }
    }
}

template<typename E>
E* clone_list(E* list, int size) {
    E* result = new E[size];
    for (int i = 0; i < size; ++i) result[i] = list[i];
    return result;
}


// ��һ������װ��Ϊһ������
template<typename E>
Node<E>* load_nodes(E* list, int size) {
    auto* node = new Node<E>;
    auto* head = node;
    for (int i = 0; i < size; ++i) {
        node->data = list[i];
        // ���һ��������һ���ڵ�
        if (i < size - 1) node->next = new Node<E>;
        node = node->next;
    }
    return head;
}


// ��ӡһ������
template<typename E>
void nodes_show(Node<E>* node) {
    auto* curr = node;
    std::cout << "Nodes[";
    while (curr != nullptr) {
        std::cout << curr->data << "->";
        curr = curr->next;
    }
    std::cout << "]" << std::endl;
}


// ��ȡlist�����ֵ O(n)
template<typename E>
E list_max(E* list, int size) {
    if (size <= 0) throw StringException("list_max()=>size must be > 0 !");
    E max = list[0];
    for (int i = 0; i < size; ++i) if (list[i] > max) max = list[i];
    return max;
}


// ��ȡlist����Сֵ O(n)
template<typename E>
E list_min(E* list, int size) {
    if (size <= 0) throw StringException("list_min()=>size must be > 0 !");
    E min = list[0];
    for (int i = 0; i < size; ++i) if (list[i] < min) min = list[i];
    return min;
}

// ��ȡlist������ƽ��ֵ O(n)
template<typename E>
double list_mean(E* list, int size) {
    if (size < 0) throw StringException("list_min()=>size must be > 0 !");
    double sum = 0.0;
    for (int i = 0; i < size; ++i) sum += list[i];
    return sum / size;
}

#endif //ALGORITHM_LIST_TOOL_H
