
int main()
{
    int size = 10;
    char* data_list = new char[size];
    for (int i = 0; i < size; ++i) data_list[i] = i + 'A';
    auto* tree = new ParentPointerTree<char>(data_list, size);

    char pair_l[] = {'A','A','A','B','C','H','E','E','E','D','F','G'};
    char pair_r[] = {'B','C','H','H','H','E','D','F','G','F','I','F'};
//    char pair_l[] = {'A','A','C','D','B'};
//    char pair_r[] = {'B','B','H','E','H'};
     int pair_size = sizeof(pair_l)/sizeof(pair_l[0]);
    auto* data_pairs = new BasePair<char>(data_list, size, pair_l, pair_r, pair_size);
    tree->build(data_pairs);
    tree->show();
    delete[] data_list;
    return 0;
}