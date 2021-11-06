#include <ctime>
#include <random>
#include <iostream>

template<typename E>
void quick_sort(E* list, int lo, int hi, int k) {
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
    else if (mid > k) quick_sort(list, lo, mid - 1, k);
    else quick_sort(list, mid + 1, hi, k);
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
    int size = 20;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = rand() % 20;
//    for (int i = 0; i < size; ++i) list[i] = size - i;
    list_show(list, size);
    quick_sort(list, 0, size - 1, 3);
    list_show(list, size);
}