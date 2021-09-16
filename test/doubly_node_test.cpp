#include "dataStructures/node/DoublyNode.h"

int main()
{
    auto* a = new DoublyNode<int>(9, nullptr, nullptr);
    auto* b = new DoublyNode<int>(8, nullptr, nullptr);
    auto* c = new DoublyNode<int>(7, nullptr, nullptr);
    DoublyNode<int>::poolShow();
    delete b;
    delete c;
    DoublyNode<int>::poolShow();
    auto* d = new DoublyNode<int>(6, nullptr, nullptr);
    DoublyNode<int>::poolShow();
    delete a;
    DoublyNode<int>::poolShow();
    delete d;
    DoublyNode<int>::poolShow();



}