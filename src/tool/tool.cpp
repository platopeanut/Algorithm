/**
* ���ߺ����⣬�����㷨����
*/

#include <ctime>

// �����������ʱ��, ����ʾ
void run_time(clock_t start, clock_t finish)
{
    double duration = (double)(finish - start) / CLOCKS_PER_SEC ;
    printf("����ʱ�䣺%fs\n", duration);
}