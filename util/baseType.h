#ifndef ALGORITHM_BASETYPE_H
#define ALGORITHM_BASETYPE_H

/**
 * 还没想好
 */

#include <ostream>
#include "./Comparable.h"

class Integer: public Comparable<Integer> {
public:
    int value = 0;
    int compareTo(Integer& o) override {
        return this->value - o.value;
    }
    friend std::ostream &operator<<(std::ostream &os, const Integer &integer) {
        os << integer.value;
        return os;
    }
};

class Double: public Comparable<Double> {
public:
    double value = 0.0;
    int compareTo(Double& o) override {
        return (int)(this->value - o.value);
    }
    friend std::ostream &operator<<(std::ostream &os, const Double &aDouble) {
        os << aDouble.value;
        return os;
    }
};


#endif //ALGORITHM_BASETYPE_H
