#ifndef ALGORITHM_COMPARE_H
#define ALGORITHM_COMPARE_H

template<typename E>
class Compare {
public:
    // 若a比b优先级高则返回true
    virtual bool prior(E a, E b) = 0;
};


// 数值最大比较器
template<typename E>
class MaxCompare : public Compare<E> {
public:
    bool prior(E a, E b) override {
        return a > b;
    }
};

// 数值最小比较器
template<typename E>
class MinCompare: public Compare<E> {
public:
    bool prior(E a, E b) override {
        return a < b;
    }
};

#endif //ALGORITHM_COMPARE_H
