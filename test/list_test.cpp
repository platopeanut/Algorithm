#include "dataStructures/list/List.h"
#include "dataStructures/list/ArrayList.cpp"
#include "dataStructures/list/LinkedList.cpp"
#include "dataStructures/list/DoublyLinkedList.cpp"
#include "dataStructures/list/tool.h"
#include <iostream>

int main()
{
    // 利用多态，用List同时测试三个不同实现类
//    List<int>* list = new ArrayList<int>;
//    List<int>* list = new LinkedList<int>;
    List<int>* list = new DoublyLinkedList<int>;
    // 初始化
    int init_nums[] = {8,3,6,1,4};
    initList(list, init_nums, sizeof(init_nums)/sizeof(init_nums[0]));
    showList(list);

    list->append(999);
    list->moveToPos(list->length()-1);
    list->insert(888);
    showList(list);

    list->moveToStart();
    list->remove();
    showList(list);

    list->moveToEnd();
    list->prev();
    std::cout << "the end:" << list->getValue() << std::endl;
    list->setValue(777);
    showList(list);

    list->moveToStart();
    list->next();
    list->currPos();
    std::cout << "curr pos:" << list->currPos() << std::endl;
    list->clear();
    showList(list);
    return 0;
}