
#ifndef ALGORITHM_KRUSKALITEM_H
#define ALGORITHM_KRUSKALITEM_H


#include <ostream>

class KruskalItem {
public:
    int from;
    int to;
    int distance;
    KruskalItem(int from = -1, int to = -1, int distance = -1) : from(from), to(to), distance(distance) {}

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

    friend std::ostream &operator<<(std::ostream &os, const KruskalItem &item) {
        os << "\nfrom: " << item.from << " to: " << item.to << " distance: " << item.distance;
        return os;
    }
};


#endif //ALGORITHM_KRUSKALITEM_H
