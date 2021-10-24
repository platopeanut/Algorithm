/**
 * ¼ÆÊýÆ÷
 */

#ifndef ALGORITHM_COUNTER_H
#define ALGORITHM_COUNTER_H

#include <iostream>
#include <string>
#include <utility>
#include "../dataStructures/list/LinkedList.h"

class Counter {
private:
    static int index;
    std::string _name;
    LinkedList<long>* list = new LinkedList<long>;
public:
    explicit Counter(std::string name):_name(std::move(name)){
        list->append(0);
    }
    Counter() {
        _name = std::to_string(index++);
        list->append(0);
    }
    long getNum(int type = 0) const {
        list->moveToPos(type);
        return list->getValue();
    }
    void tick(int type = 0) {
        list->moveToPos(type)
    }
    void show() {std::cout << "[Counter]" << _name << ": " << _num << "times" << std::endl;}
};

int Counter::index = 0;

#endif //ALGORITHM_COUNTER_H
