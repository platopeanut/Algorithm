#ifndef ALGORITHM_PARPTRPAIRS_H
#define ALGORITHM_PARPTRPAIRS_H

/**
 *  Parent Pointer Tree �д��ݵ����ݶԵĽӿ�
 */
template<typename T>
class ParPtrPairs {
public:
    /**
     * @param ��ֵ�� a, b
     * @return ���ɹ���ȡ�򷵻�true��ParPtrTree����ʱ���������
     */
    virtual bool getPair(T* a, T* b) = 0;
};

// ����ʵ����
template<typename T>
class BasePairs: public ParPtrPairs<T> {
private:
    T* data_list;
    int data_size;
    T* pair_left;
    T* pair_right;
    int pair_size;
public:
    BasePairs(T *dataList, int dataSize, T *pairLeft, T *pairRight, int pairSize)
    : data_list(dataList), data_size(dataSize), pair_left(pairLeft),
    pair_right(pairRight),pair_size(pairSize) {}
    bool getPair(T *a, T *b) override {
        if (pair_size > 0) {
            *a = pair_left[pair_size - 1];
            *b = pair_right[pair_size - 1];
            pair_size --;
            return true;
        } else {
            a = b = nullptr;
            return false;
        }
    }
};



#endif //ALGORITHM_PARPTRPAIRS_H
