#include "list/NodeWithPool.h"

int main() {
    NodeWithPool<int>* a = new NodeWithPool<int>(2, nullptr);
    NodeWithPool<int>* b = new NodeWithPool<int>(3, nullptr);
    NodeWithPool<int>* c = new NodeWithPool<int>(4, nullptr);
    delete a;
    delete b;
    delete c;
    NodeWithPool<int>::poolShow();
    NodeWithPool<int>* d = new NodeWithPool<int>(5, nullptr);
    NodeWithPool<int>::poolShow();
    delete d;
    return 0;

}