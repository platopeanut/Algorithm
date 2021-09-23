#include "dataStructures/queue/Queue.h"
#include "dataStructures/queue/ArrayQueue.cpp"
#include "dataStructures/queue/LinkedQueue.cpp"
#include <iostream>

template<typename E>
void init_queue(Queue<E>* queue, E* nums, int size);

int main()
{
//    Queue<int>* queue = new ArrayQueue<int>;
    Queue<int>* queue = new LinkedQueue<int>;
    int init_nums[] = {0,4,8,2,3};
    init_queue(queue, init_nums, sizeof(init_nums)/sizeof(init_nums[0]));
    queue->show();
    std::cout << "front value:" << queue->frontValue() << std::endl;
    queue->dequeue();
    std::cout << "length:" << queue->length() << std::endl;
    queue->show();
    queue->clear();
    queue->show();
    return 0;
}

template<typename E>
void init_queue(Queue<E>* queue, E* nums, int size)
{
    for (int i = 0; i < size; ++i) {
        queue->enqueue(nums[i]);
    }
}