#include "./dataStructures/bin_tree/BinarySearchTree.cpp"
#include <iostream>
#include <string>
int main()
{
    auto* tree = new BinarySearchTree<int, std::string>;
    tree->insert(37, "one");
    tree->insert(24, "two");
    tree->insert(42, "three");
    tree->insert(7, "four");
    tree->insert(32, "five");
    tree->insert(40, "six");
    tree->insert(42, "seven");
    tree->insert(2, "eight");
    tree->insert(120, "nine");
    tree->print();
    tree->remove(37);
    tree->print();
    tree->clear();
    tree->print();
    tree->find(-1);
}
