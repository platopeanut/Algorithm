#include <iostream>
#include "./dataStructures/stack/LinkedStack.cpp"

void insertion_sort_with_stack(Stack<int>* stack) {
    Stack<int>* target = new LinkedStack<int>;
    Stack<int>* tmp = new LinkedStack<int>;
    // first move
    target->push(stack->pop());
    while (stack->length() > 0) {
        int top = stack->pop();
        while (target->length() > 0 && target->topValue() > top) tmp->push(target->pop());
        target->push(top);
        while (tmp->length() > 0) target->push(tmp->pop());
    }
    // copy
    while (target->length() > 0) stack->push(target->pop());
    // free
    delete target;
    delete tmp;
}
int main()
{
    int size = 10;
    Stack<int>* stack = new LinkedStack<int>;
    for (int i = 0; i < size; ++i) stack->push(i);
    stack->show();
    insertion_sort_with_stack(stack);
    stack->show();
}