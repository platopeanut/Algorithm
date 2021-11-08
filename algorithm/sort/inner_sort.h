#ifndef ALGORITHM_INNER_SORT_H
#define ALGORITHM_INNER_SORT_H


/**
*  ������
*  �ڣ�������ڴ���
*/

#include "../../util/list_tool.h"
#include <vector>
#include <stack>
#include "../../dataStructures/heap/Heap.cpp"


/**
*  ��������
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
 * ð������
 * ��ÿ�α�β��ʼ��СԪ������ð�ݵ�ǰ��
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
 *  ѡ������
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
 *  ϣ������
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
    // i: ����
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = 0; j < i; ++j) {
            shell_sort_help(&list[j], size - j, i);
        }
    }
}

/**
 *  �鲢����
 */

template<typename E>
void merge(E* list, int lo, int mid, int hi, E* aux) {
    int left = lo, right = mid + 1;
    // ��list[lo..hi]���ݸ��Ƶ�aux[lo..hi]
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
*  �鲢��������Ϊ����
*/
template<typename E>
Node<E>* merge_sort(Node<E>* head) {
    // ����Ϊ0��1ֱ�ӷ���
    if (head == nullptr || head->next == nullptr) return head;
    auto* left = head;
    auto* right = head->next;
    auto* curr = head->next->next;
    auto* ll = left;
    auto* rr = right;
    bool flag = true;
    // ����������δ֪���ʲ��ý�����䱣�־���
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
    // ��ֹ��ָ
    ll->next = nullptr;
    rr->next = nullptr;
    // �������ź�
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
 *  �������򣺵ݹ�ʵ��
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
    // ������Խ�list�ȴ��ң����ͳ�����������
    shuffle(list, size);
    quick_sort_help_with_recursion(list, 0, size - 1);
}

/**
 *  �������� ջʵ��
 */

template<typename E>
void quick_sort(E* list, int size) {
    // �ȴ�������
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
 *  ������
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
//    // if heap��Ƶ���list�����ƣ�����ֱ����ôд
//    for (int i = 0; i < size; ++i) heap->removeFirst();
//    delete heap;
//}

/**
 *  ���������Ƿ��������ȷ���������
 */


/**
 *  Ͱ����(������)
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
    // ��Ϊ10��Ͱ
    int bucket_num = (max - min + 1) / 10;
    /**
     * // TODO
     *  һ��Ͱ�������Ƕ��٣�  ӳ�亯��һ���� f = array[i] / k; k^2 = n; n������Ԫ�ظ���
     */
    auto buckets = std::vector<std::vector<E>>(bucket_num);
    // push
    for (int i = 0; i < size; ++i) {
        int j = (list[i] - min) / bucket_num;
        buckets[j].push_back(list[i]);
    }
    // ÿ��Ͱ��Ԫ�ؽ��в�������
    for (int i = 0; i < buckets.size(); ++i) insertion_sort(buckets[i]);
    // join
    for (int i = 0, j = 0; i < bucket_num; ++i)
        for (int k = 0; k < buckets[i].size(); ++k)
            list[j++] = buckets[i][k];
}

/**
 *  ��������
 */

template<typename E>
void counting_sort(E* list, int size) {
    E max = list_max(list, size);
    E min = list_min(list, size);
    // TODO: С����ô��
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
 *  ��������:  ����������
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
