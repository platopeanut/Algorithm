#ifndef ALGORITHM_KRUSKALITEM_H
#define ALGORITHM_KRUSKALITEM_H

/**
 * @param graph 连通无向图
 */
class KruskalItem {
public:
    int from, to, distance;
    explicit KruskalItem(int from = -1, int to = -1, int distance = -1)
            : from(from), to(to), distance(distance) {}

    bool operator<(const KruskalItem &rhs) const {
        return distance < rhs.distance;
    }

    bool operator>(const KruskalItem &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const KruskalItem &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const KruskalItem &rhs) const {
        return !(*this < rhs);
    }
};

#endif //ALGORITHM_KRUSKALITEM_H
