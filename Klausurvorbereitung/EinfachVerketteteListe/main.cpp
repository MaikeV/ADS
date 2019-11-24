#include <iostream>
#include "List.h"

int main() {
    List list;

    list.addNode(28);
    list.addNode(10);
    list.addNode(20);
    list.addNode(50);
    list.addNode(30);
    list.addNode(25);
    list.addNode(70);

    list.print();

    list.selectionSort();

    list.print();
    return 0;
}