#ifndef ALGORITHM_SEARCH_H
#define ALGORITHM_SEARCH_H

// O(n)
template<typename E>
bool search_unsorted_list(const E* list, int size, const E key) {
    for (int i = 0; i < size; ++i) if (key == list[i]) return true;
    return false;
}

/**
 *  跳跃检索 Jump Search
 */


/**
 *  二分检索 Binary Search
 */


/**
 *  二次二分检索 Quadratic Binary Search
 */


/**
 *  自组织线性表
 */

// 计数方法 count

// 移至前端 move to front

// 转置 transpose

/**
 *  位向量 bit vector
 */

/**
 *  Hash
 */


#endif //ALGORITHM_SEARCH_H
