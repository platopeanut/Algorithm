#include "./algorithm/sort/Sort.cpp"


int main()
{
    auto* sort = new Sort<int>;
    int size = 10;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = size - i;
    Sort<int>::list_show(list, size);
//    Sort<int>::insertion_sort(list, size);
//    sort->bubble_sort(list, size);
//    sort->selection_sort(list, size);
//    sort->shell_sort(list, size);
    sort->merge_sort(list, size);
//    sort->quick_sort(list, size);
    Sort<int>::list_show(list, size);
    return 0;
}