#ifndef ALGORITHM_COMPARABLE_H
#define ALGORITHM_COMPARABLE_H

/**
 * ��û���
 * �����������Java������
 * ����algorithmĿ¼�±Ƚ���
 */

template<typename T>
class Comparable {
public:
    /**
     * if a > b return positive
     * if a == b return zero
     * if a < b return negative
     */
    virtual int compareTo(T& o) = 0;
};

#endif //ALGORITHM_COMPARABLE_H
