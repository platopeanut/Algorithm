#include "./algorithm/sort/inner_sort.h"
#include <ctime>
#include <random>
int main()
{
    srand(unsigned (time(nullptr)));
    int size = 10;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = rand() % 30000;
    list_show(list, size);
    radix_sort(list, size);
    list_show(list, size);
    delete[] list;
    return 0;
}