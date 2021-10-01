#include <iostream>
#include "./dataStructures/stack/Stack.h"
#include "./dataStructures/queue/Queue.h"
#include "./dataStructures/stack/LinkedStack.cpp"
#include "./dataStructures/queue/LinkedQueue.cpp"

template<typename E>
void reverse_queue(Queue<E>* queue)
{
    Stack<E>* stack = new LinkedStack<E>;
    int size = queue->length();
    for (int i = 0; i < size; ++i) stack->push(queue->dequeue());
    for (int i = 0; i < size; ++i) queue->enqueue(stack->pop());
}


int main()
{
    auto* queue = new LinkedQueue<int>;
    queue->show();
    for (int i = 0; i < 10; ++i) {
        queue->enqueue(i+1);
    }
    queue->show();
    reverse_queue(queue);
    queue->show();
}