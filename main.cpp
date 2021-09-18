#include "dataStructures/stack/LinkedStack.cpp"
#include <iostream>
#include <string>
int main()
{
    Stack<std::string>* stack = new LinkedStack<std::string>;
    stack->show();
    stack->push("one");
    stack->push("two");
    stack->push("three");
    stack->show();
    std::cout << stack->topValue() << std::endl;
    stack->pop();
    stack->show();
    stack->push("111");
    stack->push("222");
    stack->push("333");
    stack->show();
    stack->push("444");
}