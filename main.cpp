#include "dataStructures/queue/ArrayQueue.cpp"
#include "dataStructures/queue/Queue.h"
#include "dataStructures/queue/LinkedQueue.cpp"
int main()
{
    Queue<int>* queue = new LinkedQueue<int>();
    queue->show();
    queue->enqueue(999);
    queue->enqueue(888);
    queue->enqueue(777);
    queue->show();
    queue->dequeue();
    queue->show();
    queue->clear();
    queue->show();
}