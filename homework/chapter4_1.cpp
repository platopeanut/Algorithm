#include <iostream>
#include "list/List.h"
#include "list/LinkedList.cpp"

template <typename E>
void listShow(List<E>* list) {
    std::cout << "List[";
    list->moveToStart();
    for (int i = 0; i < list->length(); ++i) {
        std::cout << list->getValue() << ", ";
        list->next();
    }
    std::cout << "]" << std::endl;
}

int main()
{
    List<int>* list = new LinkedList<int>;
    list->append(2);
    list->append(23);
    list->append(15);
    list->append(5);
    list->append(9);
    list->moveToStart();
    listShow(list);
    // remove 15
    list->moveToPos(2);
    list->remove();
    // show
    listShow(list);
}
