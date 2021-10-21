/**
*  内排序
*  内：计算机内存中
*/
#include <iostream>

// 打印list
template<typename E>
void list_show(E* list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// 交换list中index为a，b的两个元素
template<typename E>
void swap(E* list, int a, int b) {
    E tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

// 插入排序
template<typename E>
void insertion_sort(E* list, int size) {
    for (int i = 1; i < size; ++i) {
        E tmp = list[i];
        int j = i - 1;
        while (j >= 0 && tmp < list[j]) {
            list[j+1] = list[j];
            j --;
        }
        list[j+1] = tmp;
    }
}
// 冒泡排序
// 从每次表尾开始，小元素慢慢冒泡到前面
template<typename E>
void bubble_sort(E* list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (list[j] < list[j-1]) swap(list, j, j-1);
        }
    }
}
// 选择排序
template<typename E>
void selection_sort(E* list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (list[j] < list[i]) swap(list, i, j);
        }
    }
}

// Shell排序
template<typename E>
void shell_sort(E* list, int size) {

}

// 归并排序
template<typename E>
void merge_sort(E* list, int size) {
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