#include <stack>
#include <iostream>
#include "./util/tool.h"
// 使用Stack实现快速排序
template<typename E>
void quick_sort(E* list, int size) {
    // 先打乱数组
    shuffle(list, size);
    std::stack<int> stack;
    stack.push(0);
    stack.push(size - 1);
    /**
     *  测试栈的最大深度
     */
    size_t max_depth = stack.size();

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

        // 更新最大深度值
        if (stack.size() > max_depth) max_depth = stack.size();
    }
    std::cout << "\033[32m\033[1m"
              <<"Max Depth:"
              <<"\033[0m\033[36m"
              << max_depth
              <<"\033[0m"<< std::endl;
}

/**
 *  改进版本
 */
template<typename E>
void quick_sort_forward(E* list, int size) {
    // 先打乱数组
    shuffle(list, size);
    std::stack<int> stack;
    stack.push(0);
    stack.push(size - 1);
    /**
     *  测试栈的最大深度
     */
    size_t max_depth = stack.size();

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
        /**
         *  优化策略：优先处理短的部分，所以让长的部分先入栈
         */
        if (mid - lo < hi - mid) {
            // solve mid+1..hi
            stack.push(mid + 1);
            stack.push(hi);
            // solve lo..mid-1
            stack.push(lo);
            stack.push(mid - 1);
        } else {
            // solve lo..mid-1
            stack.push(lo);
            stack.push(mid - 1);
            // solve mid+1..hi
            stack.push(mid + 1);
            stack.push(hi);
        }
        // 更新最大深度值
        if (stack.size() > max_depth) max_depth = stack.size();
    }
    std::cout << "\033[32m\033[1m"
              <<"Max Depth:"
              <<"\033[0m\033[36m"
              << max_depth
              <<"\033[0m"<< std::endl;
}
/**
 * 反向改进
 */
template<typename E>
void quick_sort_backward(E* list, int size) {
    // 先打乱数组
    shuffle(list, size);
    std::stack<int> stack;
    stack.push(0);
    stack.push(size - 1);
    /**
     *  测试栈的最大深度
     */
    size_t max_depth = stack.size();

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
        /**
         *  优化策略：优先处理短的部分，所以让长的部分先入栈
         */
        if (mid - lo < hi - mid) {
            // solve lo..mid-1
            stack.push(lo);
            stack.push(mid - 1);
            // solve mid+1..hi
            stack.push(mid + 1);
            stack.push(hi);
        } else {
            // solve mid+1..hi
            stack.push(mid + 1);
            stack.push(hi);
            // solve lo..mid-1
            stack.push(lo);
            stack.push(mid - 1);
        }
        // 更新最大深度值
        if (stack.size() > max_depth) max_depth = stack.size();
    }
    std::cout << "\033[32m\033[1m"
              <<"Max Depth:"
              <<"\033[0m\033[36m"
              << max_depth
              <<"\033[0m"<< std::endl;
}
int main()
{
    int size = 1000000;
    auto* list1 = get_randomInt_list(size, 0, size);
    auto* list2 = clone_list(list1, size);
    auto* list3 = clone_list(list1, size);

//    list_show(list1, size);
//    list_show(list2, size);
    quick_sort(list1, size);
    std::cout << "改进后：" << std::endl;
    quick_sort_forward(list2, size);
    std::cout << "反向改进：" << std::endl;
    quick_sort_backward(list3, size);
//    list_show(list1, size);
//    list_show(list2, size);
}
