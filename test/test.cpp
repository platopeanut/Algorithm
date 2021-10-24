#include <iostream>
#include "util/Timer.h"
#include "./algorithm/inner_sort.h"

int main()
{
    int size;
    std::cout << "Input Data Scale" << std::endl;
    std::cin >> size;
    //����һ����ʱ��
    auto* timer = new Timer;
    int* list = new int[size];
    // ��������
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("insertion sort");
    insertion_sort(list, size);
    timer->finish();
    // ð������
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("bubble sort");
    bubble_sort(list, size);
    timer->finish();
    // ѡ������
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("selection sort");
    selection_sort(list, size);
    timer->finish();
    // Shell����
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("shell sort");
    shell_sort(list, size);
    timer->finish();
    // �鲢����
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("merge sort");
    merge_sort(list, size);
    timer->finish();
    // ��������
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start("quick sort");
    quick_sort(list, size);
    timer->finish();
    return 0;
}