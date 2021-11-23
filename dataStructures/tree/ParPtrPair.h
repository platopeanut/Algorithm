#ifndef ALGORITHM_PARPTRPAIR_H
#define ALGORITHM_PARPTRPAIR_H

/**
 *  Parent Pointer Tree 中传递的数据对的接口
 */
template<typename T>
class ParPtrPair {
public:
    /**
     * @param 数值对 a, b
     * @return 若成功获取则返回true，ParPtrTree构建时会迭代调用
     */
    virtual bool getPair(T* a, T* b) = 0;
};

// 测试实现类
class IntPair: public ParPtrPair<int> {
private:
    int* data_list;
    int data_size;
    int* pair_left;
    int* pair_right;
    int pair_size;
public:
    IntPair(int *dataList, int dataSize, int *pairLeft, int *pairRight, int pairSize)
    : data_list(dataList), data_size(dataSize), pair_left(pairLeft),
    pair_right(pairRight),pair_size(pairSize) {}
    bool getPair(int *a, int *b) override {
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



#endif //ALGORITHM_PARPTRPAIR_H
