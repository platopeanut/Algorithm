#include "dataStructures/queue/ArrayQueue.cpp"
#include "dataStructures/queue/Queue.h"
int main()
{
    Queue<int>* queue = new ArrayQueue<int>(5);
    queue->show();
    queue->dequeue();

}