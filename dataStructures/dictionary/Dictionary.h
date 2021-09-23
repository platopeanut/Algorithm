#ifndef ALGORITHM_DICTIONARY_H
#define ALGORITHM_DICTIONARY_H

template <typename K, typename V>
class Dictionary {
private:
    void operator= (const Dictionary&) {}
    Dictionary(const Dictionary&) {}
public:
    Dictionary() {}
    virtual ~Dictionary() {}
    // 清空，初始化字典
    virtual void clear() = 0;
    // 插入键值对
    virtual void insert(const K& k, const V& v) = 0;
    // 删除键值对
    virtual V remove(const K& k) = 0;
    // 随机删除一个键值对
    virtual V removeAny() = 0;
    // 查找
    virtual V find(const K& k) const = 0;
    // 获取字典键值对个数
    virtual int size() = 0;
};


#endif //ALGORITHM_DICTIONARY_H
