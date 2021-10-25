/**
 * ¼ÆÊýÆ÷
 */

#ifndef ALGORITHM_COUNTER_H
#define ALGORITHM_COUNTER_H

#include <iostream>
#include <string>
#include <utility>
#include <map>


class Counter {
private:
    std::string _name;
    std::map<std::string, size_t>* data;
public:
    explicit Counter(std::string name = "default"):_name(std::move(name))
    { data = new std::map<std::string, size_t>;}
    ~Counter() { delete data; }
    size_t getNum(const std::string& type) const {
        return (*data)[type];
    }
    void tick(const std::string& type, size_t times = 1) {
        (*data)[type] += times;
    }
    void show() {
        std::cout << "[Counter]" << _name << ":" << std::endl;
        if (data == nullptr) return;
        for (const auto& iter: *data) std::cout << iter.first << ": " << iter.second << std::endl;
    }
};


#endif //ALGORITHM_COUNTER_H
