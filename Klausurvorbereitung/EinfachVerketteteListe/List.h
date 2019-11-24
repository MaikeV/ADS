//
// Created by mauske on 05.07.19.
//

#ifndef EINFACHVERKETTETELISTE_LIST_H
#define EINFACHVERKETTETELISTE_LIST_H


#include "ListNode.h"

class List {
private:
    int length;
    ListNode* head;

public:
    List() {
        this->length = 0;
        this->head = new ListNode;
    }

    int getLength() const {
        return this->length;
    }

    ListNode* getHead() const {
        return this->head;
    }

    void setHead(ListNode* node) {
        this->head = node;
    }

    void setLength(int val) {
        this->length = val;
    }

    void addNode(int value);
    void deleteNode(int value);
    int searchNode(int value);
    void print();
    ListNode* findPrev(ListNode * a);
    void swap(ListNode *a, ListNode *b);
    void selectionSort();
};


#endif //EINFACHVERKETTETELISTE_LIST_H
