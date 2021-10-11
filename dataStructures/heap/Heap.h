#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

#include <iostream>

template<typename E>
class Compare {
public:
    // ��a��b���ȼ����򷵻�true
    bool static prior(E a, E b) {return a > b;}
    // ����indexΪa, b��Ԫ��
    void static swap(E* list, int a, int b) {
        auto tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
    }
};
template<typename E>
class Heap {
private:
    // ������
    E* heap;
    // ����Ԫ���������ֵ
    int maxSize;
    // ��ǰ����Ԫ������
    int num;
    // helper function
    void siftDown(int pos);

public:
    // ʹ�����鴴��һ����
    Heap(E* heap, int num, int maxSize): heap(heap), num(num), maxSize(maxSize) {buildHeap();}
    int size() const {return num;}
    // ������ȫ����������û��Խ����
    bool isLeaf(int pos) const { return pos >= num/2 && pos < num; }
    int leftChild(int pos) const {return 2*pos + 1;}
    int rightChild(int pos) const {return 2*pos + 2;}
    int parent(int pos) const {return (pos - 1) / 2;}
    void buildHeap() {
        // num/2-1����ȫ�����������һ����֧�ڵ��±�
        for (int i = num/2-1; i >= 0; i--) siftDown(i);
    }

    void insert(const E& item);
    E removeFirst();
    E remove(int pos);

    void show() {
        for (int i = 0; i < num; ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};


#endif //ALGORITHM_HEAP_H
