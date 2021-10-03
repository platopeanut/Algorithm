#ifndef ALGORITHM_UALDICT_H
#define ALGORITHM_UALDICT_H

#include "Dictionary.h"
#include "KVPair.h"
#include "../list/ArrayList.cpp"
#define defaultSize 1024

// Unsorted Array-based List Dictionary
template<typename K, typename V>
class UALDict: public Dictionary<K, V>{
private:
    ArrayList<KVPair<K, V>>* list;
public:
    UALDict(int size = defaultSize) { list = new ArrayList<KVPair<K, V>>(size); }
    ~UALDict() { delete list; }
    void clear() { list->clear(); }
    void insert(const K& key, const V& value) { list->append(KVPair<K, V>(key, value)); }
    V remove(const K& key) {
        // 找不到find会报错，此时不用处理
        E tmp = find(key);
        list->remove();
        return tmp;
    }

    V removeAny() {
        if (size() == 0) throw StringException("UALDict::removeAny()==>Empty Dict");
        list->moveToEnd();
        // 这是当初ArrayList遗留下来的bug
        list->prev();
        KVPair<K, V> tmp = list->remove();
        return tmp.getValue();
    }

    V find(const K& key) const {
        // 没找到，ArrayList会自己报异常
        for (list->moveToStart(); list->currPos() < list->length(); list->next()) {
            if (key == list->getValue().getKey()) return list->getValue().getValue();
        }
    }

    int size() { return list->length(); }

};


#endif //ALGORITHM_UALDICT_H
