#include <iostream>
#include "ArrayList.cpp"

int main()
{
    ArrayList<int> arrayList(10);
    for (int i = 0; i < 5; i++)
    {
        arrayList.append(i * 4);
    }
    arrayList.show();
    return 0;
}
