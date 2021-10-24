#ifndef ALGORITHM_TIMER_H
#define ALGORITHM_TIMER_H

#include <ctime>
#include <iostream>
#include <string>

class Timer {
private:
    clock_t _start;
    clock_t _finish;
    std::string _message;
public:
    void start(const std::string& message = "") {
        std::cout << "\033[32m\033[1m"
        <<"[START] "
        <<"\033[0m\033[36m"
        <<message
        <<"\033[0m"<< std::endl;
        this->_message = message;
        _start = clock();
    }
    void finish() {
        _finish = clock();
        std::cout << "\033[32m\033[1m"
        <<"[FINISH] "
        <<"\033[0m\033[36m"
        <<this->_message
        <<"\033[31m"
        <<" cost: "
        <<"\033[1m"
        <<(double)(_finish - _start) / CLOCKS_PER_SEC << "s"
        << "\033[0m"<<std::endl;
    }
};


#endif //ALGORITHM_TIMER_H
