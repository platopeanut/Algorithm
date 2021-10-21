/**
*  ������
*  �ڣ�������ڴ���
*/
#include <iostream>

// ��ӡlist
template<typename E>
void list_show(E* list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
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

// ��������
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
// ð������
// ��ÿ�α�β��ʼ��СԪ������ð�ݵ�ǰ��
template<typename E>
void bubble_sort(E* list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (list[j] < list[j-1]) swap(list, j, j-1);
        }
    }
}
// ѡ������
template<typename E>
void selection_sort(E* list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (list[j] < list[i]) swap(list, i, j);
        }
    }
}

// Shell����
template<typename E>
void shell_sort(E* list, int size) {

}

// �鲢����
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