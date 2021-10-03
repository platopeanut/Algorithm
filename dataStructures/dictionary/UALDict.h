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
    void insert(const K& key, const V& value) {
        KVPair<K, V> tmp(key, value);
        list->append(tmp);
    }
    V remove(const K& key) {
        // �Ҳ���find�ᱨ����ʱ���ô���
        V tmp = find(key);
        list->remove();
        return tmp;
    }

    V removeAny() {
        if (size() == 0) throw StringException("UALDict::removeAny()==>Empty Dict");
        list->moveToEnd();
        // ���ǵ���ArrayList����������bug
        list->prev();
        KVPair<K, V> tmp = list->remove();
        return tmp.getValue();
    }

    V find(const K& key) const {
        for (list->moveToStart(); list->currPos() < list->length(); list->next()) {
            KVPair<K, V> tmp = list->getValue();
            if (key == tmp.getKey()) return tmp.getValue();
        }
        throw StringException("UALDict::find()==>Not Found");
    }

    int size() { return list->length(); }

};


#endif //ALGORITHM_UALDICT_H
