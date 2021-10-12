/**
*  内排序
 *  内：计算机内存中
*/
#include <iostream>

template<typename E>
void list_show(E* list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}


template<typename E>
void swap(E* list, int a, int b) {
    E tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

// 插入排序
void insertion_sort(int* list, int size) {
    for (int i = 1; i < size; ++i) {
        int tmp = list[i];
        int j = i-1;
        for (; j >= 0; --j) {
            if (tmp < list[j]) list[j+1] = list[j];
            else break;
        }
        list[j+1] = tmp;
    }
}
// 冒泡排序
void bubble_sort(int* list, int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = size-1; j > i; --j) {
            if (list[j] < list[j-1]) swap(list, j, j-1);
        }
    }
}
// 选择排序
void selection_sort(int* list, int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (list[j] < list[i]) swap(list, i, j);
        }
    }
}

// 归并排序
void merge_sort(int* list, int size) {
    if (size > 2) {
        int* a = list;
        int* b = &list[size/2];
        merge_sort(a, size/2);
        merge_sort(b, size - size/2);
        int m, n = 0;
        for (int i = 0; i < size; ++i) {

        }

    } else {

    }
}