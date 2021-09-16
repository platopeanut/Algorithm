#include "List.h"
#include "../../util/StringException.h"

template <typename E>
void showList(List<E>* list) {
    std::cout << "List[";
    list->moveToStart();
    for (int i = 0; i < list->length(); ++i) {
        std::cout << list->getValue() << ", ";
        list->next();
    }
    std::cout << "]" << std::endl;
}

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
void initList(List<E>* list, E* value, int size) {
    for (int i = 0; i < size; ++i) {
        list->append(value[i]);
    }
}

template<typename E>
LinkedList<E>* mergeList(List<E>* list1, List<E>* list2) {
    auto* result = new LinkedList<E>;
    list1->moveToStart();
    list2->moveToStart();
    for (int i = 0; i < list1->length()+list2->length(); ++i) {
        E a,b;
        try {
            a = list1->getValue();
        } catch (StringException& e) {
            result->append(list2->getValue());
            list2->next();
            continue;
        }
        try {
            b = list2->getValue();
        } catch (StringException& e) {
            result->append(list1->getValue());
            list1->next();
            continue;
        }
        if (a < b) {
            result->append(a);
            list1->next();
        } else {
            result->append(b);
            list2->next();
        }
    }
    return result;
}