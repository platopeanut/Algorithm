#ifndef ALGORITHM_COMPARABLE_H
#define ALGORITHM_COMPARABLE_H

/**
 * 还没想好
 * 该类灵感来自Java抽象类
 * 用于algorithm目录下比较器
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
