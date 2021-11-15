#include "./algorithm/search/search.h"


int main()
{
    int size = 8;
    char* list = new char[size];
    for (int i = 0; i < size; ++i) list[i] = i + 'A';
    auto* table = new Self_organizing_linear_table<char>(list, size);
    std::cout << "×ªÖÃ£º" << std::endl;
    table->show();

    char find_list[]= {'D','H','H','G','H','E','G','H','G','H','E','C','E','H','G'};
    for (char i : find_list) {
//        table->count(i);
//        table->moveToFront(i);
        table->transpose(i);
    }
    table->show();
    table->counter_show();
    delete[] list;
    delete table;
    return 0;
}