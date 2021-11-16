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
 *  ��Ծ���� Jump Search
 */


/**
 *  ���ּ��� Binary Search
 */


/**
 *  ���ζ��ּ��� Quadratic Binary Search
 */


/**
 *  ����֯���Ա�
 */
 template<typename T>
class Self_organizing_linear_table {
private:
    T* list;
    int* record;
    int size;
    Counter* counter;

    // ���ظ�ֵ��list�е��±꣬����value����list�У��򷵻�size
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
        // ϰ��9.6
        this->counter = new Counter("");
    }
    ~Self_organizing_linear_table() {
        delete[] list;
        delete[] record;
    }
    void show() { list_show(list, size); }

//    void record_show() { list_show(record, size); } // ������
    void counter_show() { counter->show(); } // ϰ��9.6

    // �������� count, ����value����list�У��򷵻�false
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

    // ����ǰ�� move to front������value����list�У��򷵻�false
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

    // ת�� transpose������value����list�У��򷵻�false
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
 *  λ���� bit vector
 */

/**
 *  Hash
 */


#endif //ALGORITHM_SEARCH_H
