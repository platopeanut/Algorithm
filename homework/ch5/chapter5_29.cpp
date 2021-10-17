#include "./dataStructures/bin_tree/HuffTree.h"

int main()
{
    char letters[16];
    int weights[16];
    int size = sizeof(letters)/ sizeof(letters[0]);
    for (int i = 0; i < size; ++i) {
        letters[i] = 'A'+i;
        // 所有字母权重相等
        weights[i] = 1;
    }
    HuffTree<char>* treeArray[size];
    for (int i = 0; i < size; ++i)
        treeArray[i] = new HuffTree<char>(letters[i], weights[i]);
    auto* result = buildHuff(treeArray, size);
    result->show();
}