#include "./dataStructures/bin_tree/HuffTree.h"

int main()
{
    char letters[] = {'Q','Z','F','M','T','S','O','E'};
    int weights[] = {2,3,10,10,10,15,20,30};
    int size = sizeof(letters)/ sizeof(letters[0]);
    HuffTree<char>* treeArray[size];
    for (int i = 0; i < size; ++i)
        treeArray[i] = new HuffTree<char>(letters[i], weights[i]);
    auto* result = buildHuff(treeArray, size);
    result->show();
}