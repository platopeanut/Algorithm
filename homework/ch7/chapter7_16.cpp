#include <iostream>
#include <random>
#include <ctime>
void swap(int* list, int a, int b) {
    auto tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

void list_show(int* list, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) std::cout << list[i] << " ";
    std::cout << "]" << std::endl;
}

// 快速3个数排序
void sort3num(int* list) {
    if (list[1] < list[0]) swap(list, 0, 1);
    if (list[2] >= list[1]) return;//compare: 2, swap: 0/1
    if (list[2] <= list[0]) {
        swap(list, 1, 2);
        swap(list, 0, 1);
        return; // compare: 3, swap:2/3
    }
    swap(list, 1, 2);
    // compare: 3, swap: 1/2
}


//// 快速5个数排序
//void sort5num(int* list) {
//
//}
//
//// 快速8个数排序
//void sort8num(int* list) {
//
//}

int main()
{
    srand(unsigned (time(nullptr)));
    int size = 3;
    int* list = new int[size];
    for (int i = 0; i < size; ++i) list[i] = rand() % 100;
    list_show(list, size);
    sort3num(list);
    list_show(list, size);
    return 0;

    // 5个数和8个数用插入排序
}