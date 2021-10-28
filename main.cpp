#include "./algorithm/sort/Sort.cpp"
#include "./algorithm/sort/inner_sort.h"
#include "util/Timer.h"

int main()
{
    auto* timer = new Timer;
    int size = 100000;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = size - i;
//    list_show(list, size);
    timer->start();
    quick_sort(list, size);
    timer->finish();
//    list_show(list, size);
//    auto* sort = new Sort<int>;
//    int size = 10000;
//    int* list = new int[size];
//    for (int i = 0; i < size; ++i) list[i] = size - i;
//    Sort<int>::list_show(list, size);
////    Sort<int>::insertion_sort(list, size);
////    sort->bubble_sort(list, size);
////    sort->selection_sort(list, size);
////    sort->shell_sort(list, size);
////    sort->merge_sort(list, size);
//    Sort<int>::quick_sort(list, size);
//    Sort<int>::list_show(list, size);
//    return 0;
}