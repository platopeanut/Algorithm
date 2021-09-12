#include "list/LinkedList.cpp"
#include "list/ArrayList.cpp"
#include <iostream>
#include "list/tool.h"



int main() {
    List<int>* list1 = new LinkedList<int>;
    List<int>* list2 = new LinkedList<int>;
    int a[] = {6,7,4,2,9,1};
    int b[] = {2,8,4,9,2,1};
    initList(list1, a, sizeof(a)/sizeof(int));
    initList(list2, b, sizeof(b)/sizeof(int));
    showList(list1);
    showList(list2);
    std::cout << "-----------------" << std::endl;
    sortList(list1);
    sortList(list2);
    showList(list1);
    showList(list2);
}