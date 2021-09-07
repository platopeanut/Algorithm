
#include <cstdio>
#include <ctime>
#include "tool/tool.cpp"
#include <vector>
int febonacci(int n) {
    if (n ==1 || n==2) return 1;
    else return febonacci(n-1) + febonacci(n-2);
}

int main(){
    clock_t start, finish; // 用来保存当前时钟的变量类型
    start = clock(); // 调用clock函数获取当前时钟
    printf("%d\n", febonacci(42));
    finish = clock();
    run_time(start, finish);

}