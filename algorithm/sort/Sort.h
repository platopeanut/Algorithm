#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H


template<typename E>
class Sort {
private:
    static void shell_sort_help(E* list, int size, int incr);
    static void merge(E* list, int lo, int mid, int hi, E* aux);
    static void merge_sort_help(E* list, int lo, int hi, E* aux);
    static int partition(E* list, int lo, int hi);
    static void quick_sort_help(E* list, int lo, int hi);
    static void swap(E* list, int a, int b);

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
