#ifndef ALGORITHM_KRUSKALITEMS_H
#define ALGORITHM_KRUSKALITEMS_H

/**
 * @param graph 连通无向图
 */

#include "../../dataStructures/tree/ParPtrPairs.h"
#include "./KruskalItem.h"

class KruskalItems: public ParPtrPairs<int>{
private:
    KruskalItem* items;
    int size;
    int curr = 0;
public:
    explicit KruskalItems(int size):size(size) {
        items = new KruskalItem[size];
    }

    ~KruskalItems() {
        delete[] items;
    }

    void add(int from, int to, int distance) {
        if (curr >= size) return;
        items[curr++] = KruskalItem(from, to, distance);
    }

    KruskalItem* getItems() {
        return this->items;
    }

    bool getPair(int *a, int *b) override {
        if (curr > 0) {
            *a = items[curr-1].from;
            *b = items[curr-1].to;
            curr --;
            return true;
        } else {
            return false;
        }
    }


};

#endif //ALGORITHM_KRUSKALITEMS_H
