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
    // ��գ���ʼ���ֵ�
    virtual void clear() = 0;
    // �����ֵ��
    virtual void insert(const K& k, const V& v) = 0;
    // ɾ����ֵ��
    virtual V remove(const K& k) = 0;
    // ���ɾ��һ����ֵ��
    virtual V removeAny() = 0;
    // ����
    virtual V find(const K& k) const = 0;
    // ��ȡ�ֵ��ֵ�Ը���
    virtual int size() = 0;
};


#endif //ALGORITHM_DICTIONARY_H
