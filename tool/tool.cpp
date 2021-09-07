/**
* 工具函数库，用于算法分析
*/

#include <ctime>

// 计算程序运行时间, 并显示
void run_time(clock_t start, clock_t finish)
{
    double duration = (double)(finish - start) / CLOCKS_PER_SEC ;
    printf("运行时间：%fs\n", duration);
}