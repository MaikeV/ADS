//
// Created by mauske on 05.07.19.
//

#ifndef EINFACHVERKETTETELISTE_LISTNODE_H
#define EINFACHVERKETTETELISTE_LISTNODE_H


class ListNode {
private:
    int value;
    ListNode* next;

public:
    ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }

    ListNode() {
        this->next = nullptr;
    }

    int getValue() const {
        return this->value;
    }

    ListNode* getNext() const {
        return this->next;
    }

    void setValue(int value) {
        this->value = value;
    }

    void setNext(ListNode* next) {
        this->next = next;
    }
};


#endif //EINFACHVERKETTETELISTE_LISTNODE_H
