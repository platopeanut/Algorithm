#include "./algorithm/sort/inner_sort.h"
#include <ostream>
#include <iostream>
#include <random>
#include <ctime>
/**
 *  带有跟踪的整数类
 */
class Int_with_track {
public:
    int value;
    int flag;
    bool _track;

    explicit Int_with_track(int value=0, bool track= false, int flag=0)
            : value(value), flag(flag), _track(track) {}

    friend std::ostream &operator<<(std::ostream &os, const Int_with_track &track) {
        if (!track._track) os << track.value;
        else os << track.value << "(" << "\033[32m\033[1m"
                << track.flag
                <<"\033[0m"<< ")";
        return os;
    }

    bool operator==(const Int_with_track &rhs) const {
        return value == rhs.value;
    }

    bool operator!=(const Int_with_track &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Int_with_track &rhs) const {
        return value < rhs.value;
    }

    bool operator>(const Int_with_track &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Int_with_track &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Int_with_track &rhs) const {
        return !(*this < rhs);
    }
};

int main()
{
    srand(unsigned (time(nullptr)));
    int size = 10;
    int track_num = 3;
    auto* list = new Int_with_track[size];
    for (int i = 0; i < size; ++i) list[i] = Int_with_track(rand() % 100);
    // 产生三个随机跟踪值
    for (int i = 0; i < track_num; ++i) {
        int index = rand()%size;
        list[index].value = 50;
        list[index].flag = i;
        list[index]._track = true;
    }
    std::cout << "插入排序：" << std::endl;
    list_show(list, size);
//    insertion_sort(list, size);
//    bubble_sort(list, size);
//    selection_sort(list, size); // 不稳定
//    shell_sort(list, size);
//    merge_sort(list, size);
//    quick_sort(list, size);
    list_show(list, size);
    return 0;
}