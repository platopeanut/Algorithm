#include "./util/list_tool.h"
#include "./algorithm/sort/inner_sort.h"

int main()
{
    int size;
    int* list = get_range_list(100000, 0, -1, &size);
    list_show(list, size);
    bucket_sort(list, size);
    list_show(list, size);
//    std::vector<int> a(10);
//    for (int i = 0; i < a.size(); ++i) a[i] = 10 - i;
//    vector_show(a);
//    insertion_sort(a);
//    vector_show(a);
}