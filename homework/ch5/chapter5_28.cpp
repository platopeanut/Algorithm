#include "./dataStructures/bin_tree/HuffTree.h"

int main()
{
    char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
    int weights[] = {2,3,5,7,11,13,17,19,23,31,37,41};
    int size = sizeof(letters)/ sizeof(letters[0]);
    HuffTree<char>* treeArray[size];
    for (int i = 0; i < size; ++i)
        treeArray[i] = new HuffTree<char>(letters[i], weights[i]);
    auto* result = buildHuff(treeArray, size);
    result->show();
}