// 二分查找算法
int binary_search(const int* list, int size, int ele) {
    int left = -1;
    int right = size;
    while (left+1 != right) {
        int i = (left + right) / 2;
        if (ele < list[i]) right = i;
        else if (ele > list[i]) left = i;
        else return i;
    }
    return -1;
}