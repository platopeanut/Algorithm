#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

#include <iostream>
#include "../../util/Compare.h"

template<typename E>
class Heap {
private:
    // ������
    E* heap;
    // ����Ԫ���������ֵ
    int maxSize;
    // ��ǰ����Ԫ������
    int num;
    // �Ƚ�����
    Compare<E>* compare;
    // helper function
    void siftDown(int pos);

    // ����indexΪa, b��Ԫ��
    void static swap(E* list, int a, int b) {
        auto tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
    }
public:
    // ʹ�����鴴��һ���ѣ�Ĭ��Ϊ����
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
    // ������ȫ����������û��Խ����
    bool isLeaf(int pos) const { return pos >= num/2 && pos < num; }
    int leftChild(int pos) const {return 2*pos + 1;}
    int rightChild(int pos) const {return 2*pos + 2;}
    int parent(int pos) const {return (pos - 1) / 2;}
    void buildHeap() {
        // num/2-1����ȫ�����������һ����֧�ڵ��±�,����д��parent(size-1)
        // ΪɶҪ�����һ����֧�ڵ㿪ʼ����Ϊ����Ҷ�ڵ������Ϊ���Ѿ����кõĶ�
        for (int i = num/2-1; i >= 0; i--) siftDown(i);
    }

    // ����һ���½ڵ�
    void insert(const E& item);
    // ɾ���Ѹ��ڵ�
    E removeFirst();
    // ����λ��ɾ�ڵ�
    E remove(int pos);

    void show();
    void heap_sort();
    void setCompare(Compare<E>* compare) {
        // ע���ڴ�й¶
        delete this->compare;
        this->compare = compare;
        // �ؽ�
        this->buildHeap();
    }
    const Compare<E>* getCompare() { return this->compare; }
};


#endif //ALGORITHM_HEAP_H
