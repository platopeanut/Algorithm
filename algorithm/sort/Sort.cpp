#include "Sort.h"
#include <iostream>
#include <ctime>
#include "../../util/Counter.h"

/**
 *  元素间比较次数、交换次数统计
 */

template<typename E>
void Sort<E>::shell_sort_help(E *list, int size, int incr, Counter* counter) {
    for (int i = incr; i < size; i += incr) {
        auto tmp = list[i];
        int j = i - incr;
        for (;j >= 0 && list[j] > tmp; j -= incr) {
            list[j + incr] = list[j];
            counter->tick("compare");
            counter->tick("swap");
        }
        list[j + incr] = tmp;
        counter->tick("swap");
    }
}

template<typename E>
void Sort<E>::merge(E *list, int lo, int mid, int hi, E *aux, Counter* counter) {
    int left = lo, right = mid + 1;
    // 将list[lo..hi]内容复制到aux[lo..hi]
    for (int i = lo; i <= hi; ++i) aux[i] = list[i];
    for (int i = lo; i <= hi; ++i) {
        counter->tick("compare", 2);
        if (right > hi || aux[left] < aux[right]) {
            list[i] = aux[left++];
            counter->tick("swap");
        } else if (left > mid || aux[left] >= aux[right]) {
            list[i] = aux[right++];
            counter->tick("swap");
        }
    }
}

template<typename E>
void Sort<E>::merge_sort_help(E *list, int lo, int hi, E *aux, Counter* counter) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort_help(list, lo, mid, aux, counter);
    merge_sort_help(list, mid+1, hi, aux, counter);
    merge(list, lo, mid, hi, aux, counter);
}

template<typename E>
int Sort<E>::partition(E *list, int lo, int hi, Counter* counter) {
    E pivot = list[lo];
    int left = lo, right = hi;
    while (left != right) {
        while (left != right && list[right] >= pivot) right --;
        list[left] = list[right];
        while (left != right && list[left] < pivot) left ++;
        list[right] = list[left];
        counter->tick("compare", 2);
        counter->tick("swap");
    }
    list[left] = pivot;
    counter->tick("swap");
    return left;
}

template<typename E>
void Sort<E>::quick_sort_help(E *list, int lo, int hi, Counter* counter) {
    if (lo >= hi) return;
    int mid = partition(list, lo, hi, counter);
    quick_sort_help(list, lo, mid - 1, counter);
    quick_sort_help(list, mid + 1, hi, counter);
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
    Counter counter("insertion_sort");
    for (int i = 1; i < size; ++i) {
        E tmp = list[i];
        int j = i - 1;
        while (j >= 0 && tmp < list[j]) {
            list[j+1] = list[j];
            j --;
            counter.tick("compare");
            counter.tick("swap"); // list[j+1] = list[j];我认为算
        }
        list[j+1] = tmp;
        counter.tick("swap");
    }
    counter.show();
}

template<typename E>
void Sort<E>::bubble_sort(E *list, int size) {
    Counter counter("bubble_sort");
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            counter.tick("compare");
            if (list[j] < list[j-1]) {
                swap(list, j, j-1);
                counter.tick("swap");
            }
        }
    }
    counter.show();
}

template<typename E>
void Sort<E>::selection_sort(E *list, int size) {
    Counter counter("selection_sort");
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i+1; j < size; ++j) {
            counter.tick("compare");
            if (list[j] < list[i]) {
                swap(list, i, j);
                counter.tick("swap");
            }
        }
    }
    counter.show();
}

template<typename E>
void Sort<E>::shell_sort(E *list, int size) {
    Counter counter("shell_sort");
    // i: 增量
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = 0; j < i; ++j) {
            shell_sort_help(&list[j], size - j, i, &counter);
        }
    }
    counter.show();
}

template<typename E>
void Sort<E>::merge_sort(E *list, int size) {
    Counter counter("merge_sort");
    E* aux = new E[size];
    merge_sort_help(list, 0, size - 1, aux, &counter);
    delete[] aux;
    counter.show();
}

template<typename E>
void Sort<E>::quick_sort(E *list, int size) {
    auto* counter = new Counter("quick sort");
    // 这里可以将list先打乱，降低出现最坏情况概率
    shuffle(list, size);
    quick_sort_help(list, 0, size - 1, counter);
    counter->show();
    delete counter;
}

template<typename E>
void Sort<E>::shuffle(E *list, int size) {
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