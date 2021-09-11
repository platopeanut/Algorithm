#include "list/LinkedList.cpp"
#include "list/ArrayList.cpp"
#include <iostream>

template<typename E>
void sortList(List<E>* list) {
    // —°‘Ò≈≈–Ú
    for (int i = 0; i < list->length()-1; ++i) {
        for (int j = i+1; j < list->length(); ++j) {
            list->moveToPos(i);
            E a = list->getValue();
            list->moveToPos(j);
            E b = list->getValue();
            if (a > b) {
                list->moveToPos(i);
                list->setValue(b);
                list->moveToPos(j);
                list->setValue(a);
            }
        }
    }
}

template<typename E>
LinkedList<E>* mergeList(List<E>* list1, List<E>* list2) {
    auto* result = new LinkedList<E>;
    list1->moveToStart();
    list2->moveToStart();
    for (int i = 0; i < list1->length()+list2->length(); ++i) {
        if (list1->getValue() == NULL) {
            result->append(list2->getValue());
            list2->next();
            continue;
        }
        if (list2->getValue() == NULL) {
            result->append(list1->getValue());
            list1->next();
            continue;
        }
        if (list1->getValue() < list2->getValue()) {
            result->append(list1->getValue());
            list1->next();
        } else {
            result->append(list2->getValue());
            list2->next();
        }
    }
    return result;
}


int main() {
    List<int>* list1 = new LinkedList<int>;
    list1->append(5);
    list1->append(4);
    list1->append(3);
    list1->append(2);
    list1->append(1);
    listShow(list1);
    sortList(list1);
    listShow(list1);
    List<int>* list2 = new LinkedList<int>;
    list2->append(9);
    list2->append(1);
    list2->append(3);
    list2->append(8);
    list2->append(-2);
    listShow(list2);
    sortList(list2);
    listShow(list2);
    std::cout << "--------------------" << std::endl;
    auto* a = mergeList(list1, list2);
    listShow(a);

}