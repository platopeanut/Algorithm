#ifndef ALGORITHM_SEARCH_H
#define ALGORITHM_SEARCH_H

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

// �������� count

// ����ǰ�� move to front

// ת�� transpose

/**
 *  λ���� bit vector
 */

/**
 *  Hash
 */


#endif //ALGORITHM_SEARCH_H
