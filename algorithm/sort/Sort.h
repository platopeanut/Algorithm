#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include "../../util/Counter.h"

template<typename E>
class Sort {
private:
    static void shell_sort_help(E* list, int size, int incr, Counter* counter);
    static void merge(E* list, int lo, int mid, int hi, E* aux, Counter* counter);
    static void merge_sort_help(E* list, int lo, int hi, E* aux, Counter* counter);
    static int partition(E* list, int lo, int hi, Counter* counter);
    static void quick_sort_help(E* list, int lo, int hi, Counter* counter);
    static void swap(E* list, int a, int b);
    static void shuffle(E* list, int size);

public:
    static void list_show(E* list, int size);
    static void insertion_sort(E* list, int size);
    static void bubble_sort(E* list, int size);
    static void selection_sort(E* list, int size);
    static void shell_sort(E* list, int size);
    static void merge_sort(E* list, int size);
    static void quick_sort(E* list, int size);
};


#endif //ALGORITHM_SORT_H
