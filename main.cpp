#include "dataStructures/list/DoublyLinkedList.cpp"
#include "dataStructures/list/tool.h"
int main()
{
    List<int>* list = new DoublyLinkedList<int>;
    showList(list);
    int a[] = {8,4,6,3};
    initList(list, a, sizeof(a)/sizeof(int));
    std::cout << list->currPos() << std::endl;
    list->moveToPos(3);
    list->prev();
    list->setValue(888);
    showList(list);
}