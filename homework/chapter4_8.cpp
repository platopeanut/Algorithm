#include "dataStructures/list/DoublyCircularLinkedList.cpp"
#include <iostream>
#include "dataStructures/list/tool.h"

int main()
{
    auto* list = new DoublyCircularLinkedList<int>;
    int init_num[] = {2,4,6,8,9};
    initList(list, init_num, sizeof(init_num)/sizeof(init_num[0]));
    showList(list);
    list->moveToEnd();
    std::cout << list->getValue() << std::endl;
    list->next();
    std::cout << list->getValue() << std::endl;
    list->moveToEnd();
    list->remove();
    showList(list);
}
