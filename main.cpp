<<<<<<< HEAD
=======
#include "list/LinkedList.cpp"
#include "list/ArrayList.cpp"
#include "list/tool.h"
#include <iostream>

int main() {
    List<int>* list1 = new LinkedList<int>;
    List<int>* list2 = new LinkedList<int>;
    int a[] = {6,7,4,2,9,-1, 888, 777};
    int b[] = {2,8,666,9,1};
    initList(list1, a, sizeof(a)/sizeof(int));
    initList(list2, b, sizeof(b)/sizeof(int));
    showList(list1);
    showList(list2);
    std::cout << "-----------------" << std::endl;
    sortList(list1);
    sortList(list2);
    showList(list1);
    showList(list2);
    std::cout << "==================" << std::endl;
    LinkedList<int>* list = mergeList(list1, list2);
    showList(list);

}
>>>>>>> 191f096adcefac425fab3b5071fd58d28bdef238
