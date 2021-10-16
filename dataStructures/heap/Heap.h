#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

#include <iostream>
#include "../../util/Compare.h"

template<typename E>
class Heap {
private:
    // 堆数组
    E* heap;
    // 堆中元素数量最大值
    int maxSize;
    // 当前堆中元素数量
    int num;
    // 比较器类
    Compare<E>* compare;
    // helper function
    void siftDown(int pos);

    // 交换index为a, b的元素
    void static swap(E* list, int a, int b) {
        auto tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
    }
public:
    // 使用数组创建一个堆，默认为最大堆
    Heap(E* heap, int num, int maxSize = 1024, Compare<E>* compare = new MaxCompare<E>)
    : num(num), maxSize(maxSize), compare(compare) {
        this->heap = new E[maxSize];
        for (int i = 0; i < num; ++i) this->heap[i] = heap[i];
        buildHeap();
    }
    ~Heap() {
        delete[] this->heap;
        delete this->compare;
    }
    int size() const {return num;}
    // 根据完全二叉树定理，没有越界检查
    bool isLeaf(int pos) const { return pos >= num/2 && pos < num; }
    int leftChild(int pos) const {return 2*pos + 1;}
    int rightChild(int pos) const {return 2*pos + 2;}
    int parent(int pos) const {return (pos - 1) / 2;}
    void buildHeap() {
        // num/2-1是完全二叉树中最后一个分支节点下标,或者写成parent(size-1)
        // 为啥要从最后一个分支节点开始？因为单个叶节点可以认为是已经排列好的堆
        for (int i = num/2-1; i >= 0; i--) siftDown(i);
    }

    // 插入一个新节点
    void insert(const E& item);
    // 删除堆根节点
    E removeFirst();
    // 根据位置删节点
    E remove(int pos);

    void show();
    void heap_sort();
    void setCompare(Compare<E>* compare) {
        // 注意内存泄露
        delete this->compare;
        this->compare = compare;
        // 重建
        this->buildHeap();
    }
    const Compare<E>* getCompare() { return this->compare; }
};


#endif //ALGORITHM_HEAP_H
