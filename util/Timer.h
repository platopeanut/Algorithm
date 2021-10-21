#ifndef ALGORITHM_TIMER_H
#define ALGORITHM_TIMER_H

#include <ctime>
#include <iostream>

class Timer {
private:
    clock_t _start;
    clock_t _finish;
public:
    void start() {
        std::cout << "[START]" << std::endl;
        _start = clock();
    }
    void finish() {
        _finish = clock();
        std::cout << "[FINISH] cost: " <<
        (double)(_finish - _start) / CLOCKS_PER_SEC << "s" << std::endl;
    }
};


#endif //ALGORITHM_TIMER_H
