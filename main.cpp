#include <iostream>
#include "LinkedList.cpp"

int main()
{
    LinkedList<int> list;
    list.append(8);
    list.append(5);
    list.append(3);
    list.insert(999);
    list.moveToEnd();
    list.insert(-111);
    list.moveToPos(1);
    list.remove();
    list.print();

}
