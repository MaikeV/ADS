//
// Created by mauske on 05.07.19.
//

#include <iostream>
#include "List.h"

void List::addNode(int value) {
    ListNode *newNode = new ListNode(value);

    if(!this->head->getNext()) {
        this->head->setNext(newNode);
        this->setLength(this->getLength() + 1);
        return;
    }

    ListNode *ptr = this->head->getNext();

    while(ptr->getNext() != nullptr) {
        ptr = ptr->getNext();
    }

    ptr->setNext(newNode);
    this->setLength(this->getLength() + 1);
}

ListNode* List::findPrev(ListNode *a) {
    ListNode *ptr = this->head;

    while(ptr->getNext() != nullptr && ptr->getNext() != a) {
        ptr = ptr->getNext();
    }

    return ptr;
}

void List::swap(ListNode *a, ListNode *b) {
    ListNode *aPrev = this->findPrev(a);
    ListNode *bPrev = this->findPrev(b);
    ListNode *bNext = b->getNext();

    if(a->getNext() == b) {
        a->setNext(bNext);
        b->setNext(a);
        aPrev->setNext(b);

        return;
    }

    b->setNext(a->getNext());
    aPrev->setNext(b);
    a->setNext(bNext);
    bPrev->setNext(a);
}

void List::selectionSort() {
    if(!this->head->getNext()) {
        return;
    }

    ListNode *ptr = this->head->getNext();
    ListNode *iter = this->head;
    ListNode *min;
    int sizeUnsorted = this->getLength() - 1;
    ListNode *firstUnsorted = ptr;

    while(ptr->getNext() != nullptr) {
        min = firstUnsorted;
        iter = ptr;

        for(int i = 0; i < sizeUnsorted; i++) {
            if(iter->getValue() < min->getValue()) {
                min = iter;
            }

            iter = iter->getNext();
        }

        swap(firstUnsorted, min);
        sizeUnsorted--;

        firstUnsorted = ptr;
        ptr = ptr->getNext();
    }
}

void List::print() {
    ListNode *ptr = this->head->getNext();

    if(!ptr) {
        std::cout << "Empty List" << std::endl << std::endl;
        return;
    }

    while(ptr) {
        std::cout << ptr->getValue() << " ";
        ptr = ptr->getNext();
    }

    std::cout << std::endl << std::endl;
}