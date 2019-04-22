//
// Created by Maike on 08.04.2019.
//

#ifndef _NODE_H
#define _NODE_H

#include "Node.h"
Node::Node() {
    key = 0;
    next = 0;
    prev = 0;
}

Node::Node(int key, Node * next, Node * prev) {
    this->key = key;
    this->next = next;
    this->prev = prev;
}

Node::~Node(){}

class Node {
public:
    int key;
    Node * next, * prev;
public:
    Node();
    Node(int key, Node * next = 0, Node * prev = 0);
    ~Node();
};
#endif