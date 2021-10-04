//template<typename E>
//void LinkedList<E>::reverse() {
//    tail = head->next;
//    if (tail == nullptr) return;
//    while (tail->next != nullptr) {
//        curr = tail->next;
//        tail->next = curr->next;
//        curr->next = head->next;
//        head->next = curr;
//    }
//}

#include "dataStructures/list/LinkedList.h"
#include "dataStructures/list/tool.h"
#include <iostream>

int main()
{
    auto* list1 = new LinkedList<int>;
    auto* list2 = new LinkedList<int>;
    auto* list3 = new LinkedList<int>;
    int nums1[] = {2, 4, 6, 8, 10};
    int nums2[] = {2};
    initList(list1, nums1, sizeof(nums1) / sizeof(nums1[0]));
    initList(list2, nums2, sizeof(nums2) / sizeof(nums2[0]));
    // 长度大于1的链表
    showList(list1);
    list1->reverse();
    showList(list1);
    // 长度为1的链表
    showList(list2);
    list1->reverse();
    showList(list2);
    // 空链表
    showList(list3);
    list1->reverse();
    showList(list3);
}