#ifndef ALGORITHM_COMPARABLE_H
#define ALGORITHM_COMPARABLE_H

template<typename T>
class Comparable {
public:
    /**
     *
     * @param o: object
     * @return -1: this < object, 0: equal, 1: greater
     */
    virtual int compareTo(T o) = 0;
};

#endif //ALGORITHM_COMPARABLE_H
