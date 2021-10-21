#include <iostream>
#include "util/Timer.h"
#include "./algorithm/inner_sort.h"

int main()
{
    auto* timer = new Timer;
    int size = 100000;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = size - i;
    timer->start();
    insertion_sort(list, size);
    timer->finish();
    timer->start();
    insertion_sort(list, size);
    timer->finish();
    return 0;
}

