//
// Created by Maike on 08.04.2019.
//

#include "Node.h"
Node::Node()
{
    next = 0;
    prev = 0;
}
Node::Node(int key, Node * next, Node * prev)
{
    this->key = key;
    this->next = next;
    this->prev = prev;
}
Node::~Node()
{
}
