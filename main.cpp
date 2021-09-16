#include "dataStructures/stack/Stack.h"
#include "dataStructures/stack/ArrayStack.cpp"
int main()
{
    Stack<int>* stack = new ArrayStack<int>(5);
    stack->show();
//    stack->pop();
    stack->push(5);
    stack->push(9);
    stack->push(1);
    stack->show();
    std::cout << stack->topValue();
//    stack->pop();
//    stack->pop();
//    stack->push(-45);
//    stack->push(0);
//    stack->show();
//    stack->push(99);
//    stack->push(98);
//    stack->show();
//    stack->push(97);
}