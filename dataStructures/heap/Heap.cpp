#include "Heap.h"
#include "../../util/StringException.h"

template<typename E>
void Heap<E>::siftDown(int pos) {
    // ���г�posΪ���ڵ�Ķ�
    // ʹ���ж�Ҷ�ڵ�Ϊ��ֹ����������ݹ�
    while (!isLeaf(pos)) {
        // ע�������lc�ش��ڣ���Ϊ��֧�ڵ�����ӽڵ㣬����Ϊ������ȫ������
        int lc = leftChild(pos); // pos��left child�±�
        int rc = rightChild(pos); // pos��right child�±�
        // rc ���ӽڵ���ܲ�������Ҫ����
        if (rc < num && Compare<E>::prior(heap[rc], heap[lc])) lc = rc;
        // ��ʱlcָ�����ҽڵ���һ��
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
    // һֱ������
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
        // ������
        while (pos != 0 && Compare<E>::prior(heap[pos], heap[parent(pos)])) {
            Compare<E>::swap(heap, pos, parent(pos));
            pos = parent(pos);
        }
        // ���³�
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
