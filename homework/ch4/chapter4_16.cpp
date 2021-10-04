#include <iostream>
#include "./util/StringException.h"
#include "./dataStructures/stack/Stack.h"
#include "./dataStructures/stack/LinkedStack.cpp"


long fibr(int n) {
    if (n >= 47 || n <= 0) throw StringException("index out of range");
    Stack<long>* stack = new LinkedStack<long>;
    for (int i = 1; i <= n; ++i) {
        if (i <= 2) {
            stack->push(1);
            continue;
        }
        long tmp_a = stack->pop();
        long tmp_b = stack->pop();
        stack->push(tmp_a);
        stack->push(tmp_a + tmp_b);
    }
    return stack->topValue();
}


int main()
{
    for (int i = 1; i < 20; ++i) {
        std::cout<<fibr(i) << " ";
    }
}