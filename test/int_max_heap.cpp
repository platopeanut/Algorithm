#include <iostream>
#include "./util/StringException.h"

// 最大堆
class Heap {
private:
    int* list;
    int size;
    int maxSize;
    static int getParent(int pos) {
        if (pos > 0) return (pos - 1) / 2;
        else return -1;
    }
    int getLeftChild(int pos) const {
        if (pos * 2 + 1 < size) return pos * 2 + 1;
        else return -1;
    }
    int getRightChild(int pos) const {
        if (pos * 2 + 2 < size) return pos * 2 + 2;
        else return -1;
    }
    void sift_down(int root) {
        int left = getLeftChild(root);
        int right = getRightChild(root);
        if (left == -1) return;
        if (right != -1 && list[right] > list[left]) left = right;
        if (list[left] > list[root]) {
            swap(left, root);
            sift_down(left);
        }
    }
    void swap(int a, int b) {
        int tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
    }
public:
    Heap(int* list, int size, int maxSize = 1024)
            :size(size), maxSize(maxSize) {
        this->list = new int[maxSize];
        for (int i = 0; i < size; ++i) this->list[i] = list[i];
        build_max_heap();
    }
    ~Heap() { delete[] list; }
    void build_max_heap() {
        for (int i = getParent(size - 1); i >= 0; --i) sift_down(i);
    }
    void show() {
        std::cout << "Heap[";
        for (int i = 0; i < size; ++i)
            std::cout << list[i] << " ";
        std::cout << "]" << std::endl;
    }
    void insert(int value) {
        if (size >= maxSize) throw StringException("max capacity");
        int curr = size ++;
        list[curr] = value;
        while (curr != 0 && list[curr] > list[getParent(curr)]) {
            swap(curr, getParent(curr));
            curr = getParent(curr);
        }
    }
    int removeMax() {
        if (size == 0) throw StringException("heap empty");
        swap(0, --size);
        if (size > 0) sift_down(0);
        return list[size];
    }
    int removeAt(int pos) {
        if (pos < 0 || pos >= size) throw StringException("index out of range");
        if (pos == --size) return list[size];
        else {
            int tmp = list[pos];
            swap(pos, size);
            // 先上走
            while (pos != 0 && list[pos] > list[getParent(pos)]) {
                swap(pos, getParent(pos));
                pos = getParent(pos);
            }
            // 再下沉
            if (size > 0) sift_down(pos);
            return tmp;
        }
    }
    int remove(int value) {
        int i = 0;
        for (; i < size; ++i) {
            if (list[i] == value) break;
        }
        if (i == size) throw StringException("cannot find it");
        return removeAt(i);
    }
    void heap_sort() {
        std::cout << "Heap Sort: ";
        while (true) {
            try {
                std::cout << removeMax() << " ";
            } catch (StringException& e) {
                break;
            }
        }
        std::cout << std::endl;
    }
};

int main()
{
//    int list[] = {10, 5, 12, 3, 2, 1, 8, 7, 9, 4};
//    int list[] = {1, 2, 3, 4, 5, 6, 7};
    int list[] = {9,3,8,1,2,6,7};
    Heap* heap = new Heap(list, sizeof(list)/ sizeof(list[0]));
    heap->show();
    heap->removeAt(4);
    heap->show();
//    heap->removeMax();
//    heap->remove(5);
//    heap->show();

}

