

namespace my_math
{
    // 数组， 数组长度， 查找元素
    int seek1(const int* list, int length, int ele)
    {
        // 顺序查找
        for (int i = 0; i < length; ++i) {
            if (*(list+i) == ele) return i;
        }
        return -1;
    }

    int seek2(const int* list, int length, int ele)
    {
        // 二分查找
        int left = 0, right = length-1;
        int i = (left + right) / 2;
        while (*(list+i) != ele)
        {
            if (*(list + i) > ele) right = i;
            else left = i;
            i = (left + right) / 2;
            if (left == right) return -1;
        }
        return i;
    }
}