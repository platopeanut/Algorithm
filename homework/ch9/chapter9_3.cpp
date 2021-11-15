#include <ctime>
#include <random>
#include <iostream>

template<typename E>
void find_k_min(E* list, int lo, int hi, int k) {
    if (lo >= hi) return;
    // partition
    E pivot = list[lo];
    int left = lo;
    int right = hi;
    while (left != right) {
        while (left != right && list[right] >= pivot) right --;
        list[left] = list[right];
        while (left != right && list[left] < pivot) left ++;
        list[right] = list[left];
    }
    int mid = left;
    list[mid] = pivot;
    // change
    if (mid == k) return;
    else if (mid > k) find_k_min(list, lo, mid - 1, k);
    else find_k_min(list, mid + 1, hi, k);
}

template<typename E>
void list_show(E* list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    srand(unsigned (time(nullptr)));
    int size = 10;
    int* list = new int[size];
    int k = 5;
    for (int i = 0; i < size; ++i) list[i] = rand() % 20;
    list_show(list, size);
    find_k_min(list, 0, size - 1, k - 1);
    list_show(list, size);
    std::cout << "第" << k << "个最小值：" << list[k - 1] << std::endl;
    delete[] list;
    return 0;
}