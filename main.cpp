#include "./dataStructures/tree/ParentPointerTree.h"

int main()
{
    int size = 10;
    int* data_list = new int[size];
    for (int i = 0; i < size; ++i) data_list[i] = size - i;
    auto* tree = new ParentPointerTree<int>(data_list, size);

    int pair_size = 5;
    int pair_l[] = {2,3,4,5,6};
    int pair_r[] = {8,8,8,8,8};
    auto* data_pairs = new IntPair(data_list, size, pair_l, pair_r, pair_size);
    tree->build(data_pairs);
    tree->show();
    delete[] data_list;
    return 0;
}