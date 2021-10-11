#include "Heap.h"
#include "../../util/StringException.h"

template<typename E>
void Heap<E>::siftDown(int pos) {
    // 排列成pos为根节点的堆
    while (!isLeaf(pos)) {
        int lc = leftChild(pos); // pos的left child下标
        int rc = rightChild(pos); // pos的right child下标
        if (rc < num && Compare<E>::prior(heap[rc], heap[lc])) lc = rc;
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
        while (pos != 0 && Compare<E>::prior(heap[pos], heap[parent(pos)])) {
            Compare<E>::swap(heap, pos, parent(pos));
            pos = parent(pos);
        }
        if (num != 0) siftDown(pos);
    }
    return heap[num];
}
