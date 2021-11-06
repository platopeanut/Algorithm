#include "./algorithm/sort/inner_sort.h"
#include <ctime>
#include <random>
int main()
{
    srand(unsigned (time(nullptr)));
    int size = 10;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = rand() % 20;

    list_show(list, size);
    auto* node = load_nodes(list, size);
    nodes_show(node);
    merge_sort(node);
    nodes_show(node);
}