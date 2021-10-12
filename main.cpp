#include "./dataStructures/heap/Heap.cpp"

int main()
{
    int list[] = {1,2,3,4,5,6,7,8,9};
    Heap<int> heap(list, sizeof(list)/ sizeof(list[0]));
    heap.show();
    heap.heap_sort();

}