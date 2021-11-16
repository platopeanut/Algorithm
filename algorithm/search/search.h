#ifndef ALGORITHM_SEARCH_H
#define ALGORITHM_SEARCH_H

#include "../../util/list_tool.h"
#include "../../util/Counter.h"

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
 template<typename T>
class Self_organizing_linear_table {
private:
    T* list;
    int* record;
    int size;
    Counter* counter;

    // 返回该值在list中的下标，若该value不在list中，则返回size
    int seek(const T value) {
        int i;
        for (i = 0; i < size; ++i) {
            counter->tick("compare");
            if (list[i] == value) {
                record[i]++;
                break;
            }
        }
        return i;
    }
public:
    Self_organizing_linear_table(const T* list, int size):size(size) {
        this->list = new T[size];
        this->record = new int[size];
        for (int i = 0; i < size; ++i) this->list[i] = list[i];
        for (int i = 0; i < size; ++i) this->record[i] = 0;
        // 习题9.6
        this->counter = new Counter("");
    }
    ~Self_organizing_linear_table() {
        delete[] list;
        delete[] record;
    }
    void show() { list_show(list, size); }

//    void record_show() { list_show(record, size); } // 测试用
    void counter_show() { counter->show(); } // 习题9.6

    // 计数方法 count, 若该value不在list中，则返回false
    bool count(const T value) {
        // seek
        int i = seek(value);
        // not found
        if (i == size) return false;
        // change list, insertion_sort
        for (int j = i - 1; j >= 0; --j) {
            counter->tick("compare");
            if (record[j+1] > record[j]) {
                swap(list, j+1, j);
                swap(record, j+1 ,j);
            }
        }
        // found
        return true;
    }

    // 移至前端 move to front，若该value不在list中，则返回false
    bool moveToFront(const T value) {
        // seek
        int i = seek(value);
        // not found
        if (i == size) return false;
        // change list
        for (int j = i-1; j >= 0; --j) {
            list[j+1] = list[j];
        }
        list[0] = value;
        // found
        return true;
    }

    // 转置 transpose，若该value不在list中，则返回false
    bool transpose(const T value) {
        // seek
        int i = seek(value);
        // not found
        if (i == size) return false;
        // change list
        if (i > 0) swap(list, i, i-1);
        // found
        return true;
    }
};


/**
 *  位向量 bit vector
 */

/**
 *  Hash
 */


#endif //ALGORITHM_SEARCH_H
