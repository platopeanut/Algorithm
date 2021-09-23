#include "dataStructures/stack/Stack.h"
#include "dataStructures/stack/ArrayStack.cpp"
#include "dataStructures/stack/LinkedStack.cpp"
#include <iostream>

template<typename E>
void init_stack(Stack<E>* stack, E* nums, int size);

int main()
{
//    Stack<int>* stack = new ArrayStack<int>;
    Stack<int>* stack = new LinkedStack<int>;
    int init_nums[] = {2,9,4,0,6};
    init_stack(stack, init_nums, sizeof(init_nums)/sizeof(init_nums[0]));
    stack->show();
    std::cout << "top value:" << stack->topValue() << std::endl;
    stack->pop();
    std::cout << "length:" << stack->length() << std::endl;
    stack->show();
    stack->clear();
    stack->show();
    return 0;
}


template<typename E>
void init_stack(Stack<E>* stack, E* nums, int size)
{
    for (int i = 0; i < size; ++i) {
        stack->push(nums[i]);
    }
}