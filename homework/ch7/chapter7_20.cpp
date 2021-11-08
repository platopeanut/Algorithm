#include "./algorithm/sort/inner_sort.h"
int main()
{
    int size = 10;
    auto* list = get_randomInt_list(10, 0, 20);
    list_show(list, size);
    auto* node = load_nodes(list, size);
    nodes_show(node);
    node = merge_sort(node);
    nodes_show(node);
}