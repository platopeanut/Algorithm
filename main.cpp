#include "list/LinkedList.cpp"
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
                E tmp = a;
                a = b;
                b = tmp;
            }
        }
    }
}

template<typename E>
void mergeLinkedList(LinkedList<E>* list1, LinkedList<E>* list2) {

}


int main() {
    List<int>* list = new LinkedList<int>;
    list->append(5);
    list->append(4);
    list->append(3);
    list->append(2);
    list->append(1);
    listShow(list);
    sortList(list);
    listShow(list);
}