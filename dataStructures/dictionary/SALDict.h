#ifndef ALGORITHM_SALDICT_H
#define ALGORITHM_SALDICT_H

#include "./Dictionary.h"
#include "../list/SortedArrayList.h"
#define defaultSize 1024
template<typename K, typename V>
class SALDict: public Dictionary<K, V> {
private:
    SortedArrayList<K, V>* list;
public:
    SALDict(int size = defaultSize) { list = new SortedArrayList<K, V>(size); }
    ~SALDict() {delete list;}
    void clear() {list->clear();}
    void insert(const K& key, const V& value) {
        KVPair<K, V> tmp(key, value);
        list->insert(tmp);
    }
    V remove(const K& key) {
        V tmp =
    }
};


#endif //ALGORITHM_SALDICT_H
