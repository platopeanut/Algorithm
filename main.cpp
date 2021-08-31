#include <iostream>
#include <time.h>
using namespace std;


int main()
{
    const long N = 1e9;
    long* list = new long[N];
    for (long i = 0; i < N; ++i) {
        *(list + i) = i;
    }
    // Ë³Ðò²éÕÒ
//    long target = -1;
//    cin >> target;
    long target = 1e9-1;
    time_t start,end;
    start =time(NULL);
    for (long i = 0; i < N; ++i) {
        if (list[i] == target)
            cout << "Get it ! " << i;
    }
    end =time(NULL);
    printf("time=%d\n",difftime(end,start));
}