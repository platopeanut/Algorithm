#ifndef ALGORITHM_SORTEDARRAYLIST_H
#define ALGORITHM_SORTEDARRAYLIST_H


#include "./ArrayList.h"
#include "../dictionary/KVPair.h"
#define defaultSize 1024

template<typename K, typename V>
class SortedArrayList: protected ArrayList<KVPair<K, V>> {
public:
    SortedArrayList(int size = defaultSize)
        : ArrayList<KVPair<K, V>>(size) {}
    ~SortedArrayList() {}
    void insert(KVPair<K, V>& kvPair) {
        KVPair<K, V> curr;
        for (moveToStart(); currPos() < length(); next()) {
            curr = getValue();
            if (curr.getKey() > kvPair.getKey()) break;
        }
        ArrayList<KVPair<K, V>>::insert(kvPair);
    }
    ArrayList<KVPair<K, V>>::clear;
    ArrayList<KVPair<K, V>>::remove;
    ArrayList<KVPair<K, V>>::moveToStart;
    ArrayList<KVPair<K, V>>::moveToEnd;
    ArrayList<KVPair<K, V>>::prev;
    ArrayList<KVPair<K, V>>::next;
    ArrayList<KVPair<K, V>>::length;
    ArrayList<KVPair<K, V>>::currPos;
    ArrayList<KVPair<K, V>>::moveToPos;
    ArrayList<KVPair<K, V>>::getValue;
};


#endif //ALGORITHM_SORTEDARRAYLIST_H
