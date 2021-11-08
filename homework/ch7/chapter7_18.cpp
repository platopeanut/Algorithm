#include <iostream>
#include "./util/list_tool.h"


int main()
{
    int size = 5;
    auto* list = get_randomInt_list(size,0,10);
    list_show(list, size);
    std::cout << "max: " << list_max(list, size) << std::endl;
    std::cout << "min: " << list_min(list, size) << std::endl;
    std::cout << "mean: " << list_mean(list, size) << std::endl;

}

