#include <iostream>
#include "util/Timer.h"
#include "./algorithm/inner_sort.h"

int main()
{
    int size;
    std::cout << "Input Data Scale" << std::endl;
    std::cin >> size;
    //创建一个计时器
    auto* timer = new Timer;
    int* list = new int[size];
    // 插入排序
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("insertion sort");
    insertion_sort(list, size);
    timer->finish();
    // 冒泡排序
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("bubble sort");
    bubble_sort(list, size);
    timer->finish();
    // 选择排序
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("selection sort");
    selection_sort(list, size);
    timer->finish();
    // Shell排序
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("shell sort");
    shell_sort(list, size);
    timer->finish();
    // 归并排序
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("merge sort");
    merge_sort(list, size);
    timer->finish();
    // 快速排序
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("quick sort");
    quick_sort(list, size);
    timer->finish();
    return 0;
}