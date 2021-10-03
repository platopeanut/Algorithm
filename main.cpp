#include "./dataStructures/dictionary/UALDict.h"
#include <iostream>
#include <string>

int main()
{
    auto* dict = new UALDict<std::string , int>;
    dict->insert("one", 111);
    dict->insert("two", 222);
    dict->insert("three", 333);

    dict->remove("four");

    while (dict->size() > 0) {
        std::cout << dict->removeAny() << std::endl;
    }


}