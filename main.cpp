#include <iostream>
#include "core.cpp"
#include <chrono>
using namespace std;
using namespace chrono;


int main()
{
    const int n = 1e9;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    auto start = system_clock::now();
    cout << seek2(a, n, n-1) << endl;
    auto finish = system_clock::now();
    auto duration = duration_cast<microseconds>(finish - start);
    auto cost = double(duration.count())*microseconds::period::num / microseconds::period::den;
    cout << cost;
    delete[] a;
}