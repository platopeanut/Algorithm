#include <iostream>
#include "./util/Counter.h"

int main()
{
    auto* counter = new Counter;
    for (int i = 0; i < 10; ++i) counter->tick();
    counter->show();
    auto* counter1 = new Counter;
    for (int i = 0; i < 10; ++i) counter1->tick();
    counter1->show();
}