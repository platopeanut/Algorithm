
#include <cstdio>
#include <ctime>
#include "tool/tool.cpp"
#include <vector>
int febonacci(int n) {
    if (n ==1 || n==2) return 1;
    else return febonacci(n-1) + febonacci(n-2);
}

int main(){
    clock_t start, finish; // �������浱ǰʱ�ӵı�������
    start = clock(); // ����clock������ȡ��ǰʱ��
    printf("%d\n", febonacci(42));
    finish = clock();
    run_time(start, finish);

}