#include "Heap.h"
#include "../../util/StringException.h"

template<typename E>
void Heap<E>::siftDown(int pos) {
    // 排列成pos为根节点的堆
    // 使用判断叶节点为终止条件来替代递归
    while (!isLeaf(pos)) {
        // 注意这里的lc必存在，因为分支节点必有子节点，又因为堆是完全二叉树
        int lc = leftChild(pos); // pos的left child下标
        int rc = rightChild(pos); // pos的right child下标
        // rc 右子节点可能不存在需要检验
        if (rc < num && Compare<E>::prior(heap[rc], heap[lc])) lc = rc;
        // 此时lc指向左右节点大的一个
        if (Compare<E>::prior(heap[pos], heap[lc])) return;
        Compare<E>::swap(heap, pos, lc);
        pos = lc;
    }
}

template<typename E>
void Heap<E>::insert(const E &item) {
    if (num >= maxSize) throw StringException("Heap<E>::insert==>Heap is full");
    int curr = num++;
    heap[curr] = item;
    // 一直往上走
    while (curr != 0 && Compare<E>::prior(heap[curr], heap[parent(curr)])) {
        Compare<E>::swap(heap, curr, parent(curr));
        curr = parent(curr);
    }
}

template<typename E>
E Heap<E>::removeFirst() {
    if (num <= 0) throw StringException("Heap<E>::removeFirst()==>Heap is empty");
    Compare<E>::swap(heap, 0, --num);
    if (num != 0) siftDown(0);
    return heap[num];
}

template<typename E>
E Heap<E>::remove(int pos) {
    if (pos < 0 || pos >= num) throw StringException("Heap<E>::remove==>Bad Position");
    if (pos == num - 1) num --;
    else {
        Compare<E>::swap(heap, pos, --num);
        // 先上走
        while (pos != 0 && Compare<E>::prior(heap[pos], heap[parent(pos)])) {
            Compare<E>::swap(heap, pos, parent(pos));
            pos = parent(pos);
        }
        // 后下沉
        if (num != 0) siftDown(pos);
    }
    return heap[num];
}


template<typename E>
void Heap<E>::show() {
    std::cout << "Heap[";
    for (int i = 0; i < num; ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename E>
void Heap<E>::heap_sort() {
    std::cout << "Heap Sort: ";
    while (true) {
        try {
            std::cout << removeFirst() << " ";
        } catch (StringException& e) {
            break;
        }
    }
    std::cout << std::endl;
}
