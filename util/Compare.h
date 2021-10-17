#ifndef ALGORITHM_COMPARE_H
#define ALGORITHM_COMPARE_H

template<typename E>
class Compare {
public:
    // ��a��b���ȼ����򷵻�true
    virtual bool prior(E a, E b) = 0;
};


// ��ֵ���Ƚ���
template<typename E>
class MaxCompare : public Compare<E> {
public:
    bool prior(E a, E b) override {
        return a > b;
    }
};

// ��ֵ��С�Ƚ���
template<typename E>
class MinCompare: public Compare<E> {
public:
    bool prior(E a, E b) override {
        return a < b;
    }
};

#endif //ALGORITHM_COMPARE_H
