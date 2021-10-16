#include "./dataStructures/bin_tree/BinarySearchTree.cpp"
#include <cstdlib>
#include <iostream>

// 产生[a,b]之间的随机整数
int randInt(int a, int b) {
    return rand()%(b - a + 1) + a;
}

int tree_sum_helper(BSTNode<int, int>* node) {
    if (node == nullptr) return 0;
    return node->getElement() + tree_sum_helper(node->getLeft()) + tree_sum_helper(node->getRight());
}
int tree_sum(BinarySearchTree<int, int>* tree) { return tree_sum_helper(tree->getRoot()); }


int main()
{
    auto* tree = new BinarySearchTree<int, int>;
    int list[10];
    for (int i = 0; i < 10; ++i) list[i] = randInt(0, 10);
    // 显示list
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        std::cout << list[i] << " ";
        sum += list[i];
    }
    std::cout << "\nsum: " << sum << std::endl;
    // 依次添加到tree中
    for (int i = 0; i < 10; ++i) tree->insert(list[i], list[i]);
    // 计算
    std::cout << "计算BST所有节点值之和:" << tree_sum(tree) << std::endl;
    return 0;
}