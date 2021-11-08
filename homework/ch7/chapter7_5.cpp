#include <iostream>
#include <random>
#include <ctime>
// 原生选择排序
template<typename E>
void selection_sort(E* list, int size) {
    int compare = 0, swap = 0;
    for (int i = 0; i < size - 1; ++i) {
        int small_index = i;
        for (int j = i+1; j < size; ++j) {
            compare ++;
            if (list[j] < list[i]) small_index = j;
        }
        swap += 1;
        auto tmp = list[i];
        list[i] = list[small_index];
        list[small_index] = tmp;

    }
    std::cout << "compare:" << compare << " swap:" << swap << std::endl;
}

// 改进
template<typename E>
void selection_sort_upgrade(E* list, int size) {
    int compare = 0, swap = 0;
    for (int i = 0; i < size - 1; ++i) {
        int small_index = i;
        for (int j = i+1; j < size; ++j) {
            compare ++;
            if (list[j] < list[i]) small_index = j;
        }
        // 若发现index没有变化则直接进入下一轮
        if (small_index == i) continue;
        swap += 1;
        auto tmp = list[i];
        list[i] = list[small_index];
        list[small_index] = tmp;

    }
    std::cout << "compare:" << compare << " swap:" << swap << std::endl;
}

template<typename E>
void list_show(E* list, int size) {
    for (int i = 0; i < size; ++i) std::cout << list[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int size = 10;
    int* list1 = new int[size];
    int* list2 = new int[size];
    srand((unsigned) time(nullptr));
    for (int i = 0; i < size; ++i) list1[i] = list2[i] = rand() % 100;
    list_show(list1, size);
    selection_sort(list1, size);
    list_show(list1, size);
    list_show(list2, size);
    selection_sort_upgrade(list2, size);
    list_show(list2, size);
    return 0;
}

// 测试时间
int main()
{
    Timer timer;
    int size = 3000;
    int* list1 = new int[size];
    int* list2 = new int[size];
    srand((unsigned) time(nullptr));
    for (int i = 0; i < size; ++i) list1[i] = list2[i] = rand() % size;
    timer.start("优化前");
    selection_sort(list1, size);
    timer.finish();
    timer.start("优化后");
    selection_sort_upgrade(list2, size);
    timer.finish();
    return 0;
}