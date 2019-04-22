//
// Created by Maike on 08.04.2019.
//

#ifndef _NODE_H
#define _NODE_H

template <class T> class Node {
public:
    T key;
    Node * next, * prev;
public:
    Node();
    Node(T key, Node * next = 0, Node * prev = 0);
    ~Node();
};

template <class T>
Node<T>::Node() {
    key = 0;
    next = 0;
    prev = 0;
}

template <class T>
Node<T>::Node(T key, Node<T> * next, Node<T> * prev) {
    this->key = key;
    this->next = next;
    this->prev = prev;
}

template <class T>
Node<T>::~Node(){}

#endif