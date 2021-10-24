#include "Sort.h"
#include <iostream>
#include "../../util/Counter.h"

template<typename E>
void Sort<E>::shell_sort_help(E *list, int size, int incr) {
    for (int i = incr; i < size; i += incr) {
        auto tmp = list[i];
        int j = i - incr;
        for (;j >= 0 && list[j] > tmp; j -= incr) {
            list[j + incr] = list[j];
        }
        list[j + incr] = tmp;
    }
}

template<typename E>
void Sort<E>::merge(E *list, int lo, int mid, int hi, E *aux) {
    int left = lo, right = mid + 1;
    // 将list[lo..hi]内容复制到aux[lo..hi]
    for (int i = lo; i <= hi; ++i) aux[i] = list[i];
    for (int i = lo; i <= hi; ++i) {
        if (right > hi || aux[left] < aux[right]) list[i] = aux[left++];
        else if (left > mid || aux[left] >= aux[right]) list[i] = aux[right++];
    }
}

template<typename E>
void Sort<E>::merge_sort_help(E *list, int lo, int hi, E *aux) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort_help(list, lo, mid, aux);
    merge_sort_help(list, mid+1, hi, aux);
    merge(list, lo, mid, hi, aux);
}

template<typename E>
int Sort<E>::partition(E *list, int lo, int hi) {
    E pivot = list[lo];
    int left = lo, right = hi;
    while (left != right) {
        while (right != lo && list[right] >= pivot) right --;
        list[left] = list[right];
        while (left != hi && list[left] < pivot) left ++;
        list[right] = list[left];
    }
    list[left] = pivot;
    return left;
}

template<typename E>
void Sort<E>::quick_sort_help(E *list, int lo, int hi) {
    if (lo >= hi) return;
    int mid = partition(list, lo, hi);
    quick_sort_help(list, lo, mid - 1);
    quick_sort_help(list, mid + 1, hi);
}

template<typename E>
void Sort<E>::list_show(E *list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename E>
void Sort<E>::swap(E *list, int a, int b) {
    E tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

template<typename E>
void Sort<E>::insertion_sort(E *list, int size) {
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

template<typename E>
void Sort<E>::bubble_sort(E *list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (list[j] < list[j-1]) swap(list, j, j-1);
        }
    }
}

template<typename E>
void Sort<E>::selection_sort(E *list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (list[j] < list[i]) swap(list, i, j);
        }
    }
}

template<typename E>
void Sort<E>::shell_sort(E *list, int size) {
    // i: 增量
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = 0; j < i; ++j) {
            shell_sort_help(&list[j], size - j, i);
        }
    }
}

template<typename E>
void Sort<E>::merge_sort(E *list, int size) {
    E* aux = new E[size];
    merge_sort_help(list, 0, size - 1, aux);
    delete[] aux;
}

template<typename E>
void Sort<E>::quick_sort(E *list, int size) {
    // 这里可以将list先打乱，降低出现最坏情况概率
    quick_sort_help(list, 0, size - 1);
}
