#include "./dataStructures/bin_tree/BinarySearchTree.cpp"


template<typename K, typename V>
int smallCount(BSTNode<K, V>* root, K& key) {
    if (root == nullptr) return 0;
    if (root->getKey() <= key) {
        return 1 + smallCount(root->getLeft(), key) + smallCount(root->getRight(), key);
    }
    else return smallCount(root->getLeft(), key);
}


int main()
{
    // 初始化一个BST
    int list[] = {1,4,6,3,7,2,8,3,7,0,1,2,3,4,5,56,-1,1,2,4};
    auto* tree = new BinarySearchTree<int, int>;
    for (int i = 0; i < sizeof(list)/ sizeof(list[0]); ++i) tree->insert(list[i], list[i]);
    int key = 5;
    // 验证结果
    int sum = 0;
    for (int i = 0; i < sizeof(list)/ sizeof(list[0]); ++i) {
        if (list[i] <= key) sum ++;
    }
    std::cout << "验证结果: " << sum << std::endl;
    std::cout << "BST结果：" << smallCount(tree->getRoot(), key) << std::endl;
    return 0;
}