#ifndef ALGORITHM_KVPAIR_H
#define ALGORITHM_KVPAIR_H

// ¼üÖµ¶Ô

template<typename K, typename V>
class KVPair {
private:
    K key;
    V value;
public:
    KVPair() {}
    KVPair(K key, V value): key(key), value(value) {}
    KVPair(const KVPair& KVPair): key(KVPair.key), value(KVPair.value) {}
    void operator=(const KVPair& KVPair): key(kVpair.key), value(kVpair.value) {}
    K getKey() {return key;}
    void setKey(K key) { this->key = key;}
    V getValue() {return value;}
};


#endif //ALGORITHM_KVPAIR_H
