#include <iostream>
#include "./dataStructures/stack/LinkedStack.cpp"

//enum HanoiOp { DO_MOVE, DO_Hanoi };
//class HanoiObj {
//public:
//    HanoiOp op;
//    int num;
//    char start, tmp, goal;
//    HanoiObj(int num, char start, char tmp, char goal)
//    : num(num), start(start), tmp(tmp), goal(goal) {op = DO_Hanoi;}
//    HanoiObj(char start, char goal)
//    : start(start), goal(goal) {op = DO_MOVE;}
//};
//
//void Hanoi(int num, char start, char tmp, char goal, Stack<HanoiObj*>* stack)
//{
//    stack->push(new HanoiObj(num, start, tmp, goal));
//    HanoiObj* obj;
//    while (stack->length() > 0) {
//        obj = stack->pop();
//        if (obj->op == DO_MOVE) std::cout << obj->start << " to " << obj->goal << std::endl;
//        else if (obj->num > 0) {
//            // in reverse
//            stack->push(new HanoiObj(obj->num-1, obj->tmp, obj->start, obj->goal));
//            stack->push(new HanoiObj(obj->start, obj->goal));
//            stack->push(new HanoiObj(obj->num-1, obj->start, obj->goal, obj->tmp));
//        }
//        delete obj;
//    }
//}

struct HanoiStatus {
    int num;
    char start;
    char tmp;
    char goal;
};


void Hanoi(int num, char start, char tmp, char goal, Stack<HanoiStatus*>* stack)
{
    stack->push(new HanoiStatus{num, start, tmp, goal});
    while (stack->length() > 0) {
        HanoiStatus* handle = stack->pop();
        if (handle->num == 1) std::cout << handle->start << " to " << handle->goal << std::endl;
        else if (handle->num > 1) {
            stack->push(new HanoiStatus{handle->num-1, handle->tmp, handle->start, handle->goal});
            stack->push(new HanoiStatus{1, handle->start, ' ', handle->goal});
            stack->push(new HanoiStatus{handle->num-1, handle->start, handle->goal, handle->tmp});
        }
        delete handle;
    }
}

int main()
{
    Stack<HanoiStatus*>* stack = new LinkedStack<HanoiStatus*>;
//    Stack<HanoiObj*>* stack = new LinkedStack<HanoiObj*>;
    Hanoi(3, 'A', 'B', 'C', stack);
}