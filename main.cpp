#include<iostream>
#include"core/search.c"

using namespace std;

int main()
{
    int li[] = {1,2,3,5,7,9,11,23};
    int result = binary_search(li, sizeof(li)/sizeof(int), 4);
    cout << result << endl;
}