#ifndef ALGORITHM_INNER_SORT_H
#define ALGORITHM_INNER_SORT_H


/**
*  内排序
*  内：计算机内存中
*/

#include "../../util/list_tool.h"
#include <vector>
#include <stack>
#include "../../dataStructures/heap/Heap.cpp"


/**
*  插入排序
*/

template<typename E>
void insertion_sort(E* list, int size) {
    for (int i = 1; i < size; ++i) {
        E tmp = list[i];
        int j = i - 1;
        while (j >= 0 && tmp < list[j]) {
            list[j+1] = list[j];
            j --;
        }
        list[j+1] = tmp;
    }
}

template<typename E>
void insertion_sort(std::vector<E>& list) {
    for (int i = 1; i < list.size(); ++i) {
        E tmp = list[i];
        int j = i - 1;
        while (j >= 0 && tmp < list[j]) {
            list[j+1] = list[j];
            j --;
        }
        list[j+1] = tmp;
    }
}

/**
 *
 * 冒泡排序
 * 从每次表尾开始，小元素慢慢冒泡到前面
 */

template<typename E>
void bubble_sort(E* list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (list[j] < list[j-1]) swap(list, j, j-1);
        }
    }
}

/**
 *  选择排序
 */

template<typename E>
void selection_sort(E* list, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (list[j] < list[i]) swap(list, i, j);
        }
    }
}

/**
 *  希尔排序
 */

template<typename E>
void shell_sort_help(E* list, int size, int incr) {
    for (int i = incr; i < size; i += incr) {
        auto tmp = list[i];
        int j = i - incr;
        for (;j >= 0 && list[j] > tmp; j -= incr) {
            list[j + incr] = list[j];
        }
        list[j + incr] = tmp;
    }
}
template<typename E>
void shell_sort(E* list, int size) {
    // i: 增量
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = 0; j < i; ++j) {
            shell_sort_help(&list[j], size - j, i);
        }
    }
}

/**
 *  归并排序
 */

template<typename E>
void merge(E* list, int lo, int mid, int hi, E* aux) {
    int left = lo, right = mid + 1;
    // 将list[lo..hi]内容复制到aux[lo..hi]
    for (int i = lo; i <= hi; ++i) aux[i] = list[i];
    for (int i = lo; i <= hi; ++i) {
        if (right > hi || aux[left] < aux[right]) list[i] = aux[left++];
        else if (left > mid || aux[left] >= aux[right]) list[i] = aux[right++];
    }
}
template<typename E>
void merge_sort_help(E* list, int lo, int hi, E* aux) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort_help(list, lo, mid, aux);
    merge_sort_help(list, mid+1, hi, aux);
    merge(list, lo, mid, hi, aux);
}
template<typename E>
void merge_sort(E* list, int size) {
    E* aux = new E[size];
    merge_sort_help(list, 0, size - 1, aux);
    delete[] aux;
}


/**
*  归并排序：输入为链表
*/
template<typename E>
Node<E>* merge_sort(Node<E>* head) {
    // 长度为0或1直接返回
    if (head == nullptr || head->next == nullptr) return head;
    auto* left = head;
    auto* right = head->next;
    auto* curr = head->next->next;
    auto* ll = left;
    auto* rr = right;
    bool flag = true;
    // 由于链表长度未知，故采用交替分配保持均分
    while (curr != nullptr) {
        if (flag) {
            ll->next = curr;
            ll = ll->next;
            flag = !flag;
        } else {
            rr->next = curr;
            rr = rr->next;
            flag = !flag;
        }
        curr = curr->next;
    }
    // 防止乱指
    ll->next = nullptr;
    rr->next = nullptr;
    // 先左右排好
    left = merge_sort(left);
    right = merge_sort(right);
    // merge
    // first
    if (right->data < left->data) {
        head = right;
        right = right->next;
    } else {
        head = left;
        left = left->next;
    }
    auto* hh = head;
    while (true) {
        if (left == nullptr && right == nullptr) break;
        else if (left == nullptr) {
            hh->next = right;
            right = right->next;
            hh = hh->next;
        } else if (right == nullptr) {
            hh->next = left;
            left = left->next;
            hh = hh->next;
        } else if (left->data < right->data) {
            hh->next = left;
            left = left->next;
            hh = hh->next;
        } else {
            hh->next = right;
            right = right->next;
            hh = hh->next;
        }
    }
    hh->next = nullptr;
    return head;
}


/**
 *  快速排序：递归实现
 */

template<typename E>
int partition(E* list, int lo, int hi) {
    E pivot = list[lo];
    int left = lo, right = hi;
    while (left != right) {
        while (right != lo && list[right] >= pivot) right --;
        list[left] = list[right];
        while (left != hi && list[left] < pivot) left ++;
        list[right] = list[left];
    }
    list[left] = pivot;
    return left;
}
template<typename E>
void quick_sort_help_with_recursion(E* list, int lo, int hi) {
    if (lo >= hi) return;
    int mid = partition(list, lo, hi);
    quick_sort_help_with_recursion(list, lo, mid - 1);
    quick_sort_help_with_recursion(list, mid + 1, hi);
}
template<typename E>
void quick_sort_with_recursion(E* list, int size) {
    // 这里可以将list先打乱，降低出现最坏情况概率
    shuffle(list, size);
    quick_sort_help_with_recursion(list, 0, size - 1);
}

/**
 *  快速排序： 栈实现
 */

template<typename E>
void quick_sort(E* list, int size) {
    // 先打乱数组
    shuffle(list, size);
    std::stack<int> stack;
    stack.push(0);
    stack.push(size - 1);
    while (!stack.empty()) {
        int hi = stack.top();
        stack.pop();
        int lo = stack.top();
        stack.pop();
        // !!!!!!!!!!check
        if (lo >= hi) continue;
        // partition
        int left = lo, right = hi;
        E pivot = list[left];
        while (left != right) {
            while (left != right && list[right] >= pivot) right --;
            list[left] = list[right];
            while (left != right && list[left] < pivot) left ++;
            list[right] = list[left];
        }
        int mid = left;
        list[mid] = pivot;
        // solve lo..mid-1
        stack.push(lo);
        stack.push(mid - 1);
        // solve mid+1..hi
        stack.push(mid + 1);
        stack.push(hi);
    }
}


/**
 *  堆排序
 */

template<typename E>
void heap_sort(E* list, int size) {
    auto* heap = new Heap<E>(list, size, size, new MinCompare<E>);
    for (int i = 0; i < size; ++i) list[i] = heap->removeFirst();
    delete heap;
}

//template<typename E>
//void heap_sort(E* list, int size) {
//    auto* heap = new Heap<E>(list, size, size, new MaxCompare<E>);
//    // if heap设计的是list不复制，可以直接这么写
//    for (int i = 0; i < size; ++i) heap->removeFirst();
//    delete heap;
//}

/**
 *  以下排序都是分配排序，先分类再排序
 */


/**
 *  桶排序(箱排序)
 */

//template<typename E>
//void bucket_sort(E* list, int size) {
//    E* tmp = new E[size];
//    for (int i = 0; i < size; ++i) tmp[list[i]] = list[i];
//    for (int i = 0; i < size; ++i) list[i] = tmp[i];
//    delete[] tmp;
//}

template<typename E>
void bucket_sort(E* list, int size) {
    E max = list_max(list, size);
    E min = list_min(list, size);
    // 分为10个桶
    int bucket_num = (max - min + 1) / 10;
    /**
     * // TODO
     *  一般桶的数量是多少？  映射函数一般是 f = array[i] / k; k^2 = n; n是所有元素个数
     */
    auto buckets = std::vector<std::vector<E>>(bucket_num);
    // push
    for (int i = 0; i < size; ++i) {
        int j = (list[i] - min) / bucket_num;
        buckets[j].push_back(list[i]);
    }
    // 每个桶内元素进行插入排序
    for (int i = 0; i < buckets.size(); ++i) insertion_sort(buckets[i]);
    // join
    for (int i = 0, j = 0; i < bucket_num; ++i)
        for (int k = 0; k < buckets[i].size(); ++k)
            list[j++] = buckets[i][k];
}

/**
 *  计数排序
 */

template<typename E>
void counting_sort(E* list, int size) {
    E max = list_max(list, size);
    E min = list_min(list, size);
    // TODO: 小数怎么办
    int length = max - min + 1;
    E* count_list = new E[length];
    // reset
    for (int i = 0; i < length; ++i) count_list[i] = 0;
    // count
    for (int i = 0; i < size; ++i) count_list[list[i] - min] ++;
    // collect
    for (int i = 0, index = 0; i < length; ++i)
        for (int j = 0; j < count_list[i]; ++j)
            list[index++] = i + min;
}

/**
 *  基数排序:  适用于整数
 */
void radix_sort(int* list, int size) {
    const int RADIX = 10;
    int max = list_max(list, size);
    int placement = 1;
    while (placement <= max) {
        std::vector<std::vector<int>> buckets(RADIX);
        // push
        for (int i = 0; i < size; ++i) {
            buckets[(list[i] / placement) % RADIX].push_back(list[i]);
        }
        // collect
        for (int i = 0, index = 0; i < RADIX; ++i)
            for (int j : buckets[i])
                list[index++] = j;
        placement *= RADIX;
    }
}


#endif //ALGORITHM_INNER_SORT_H
