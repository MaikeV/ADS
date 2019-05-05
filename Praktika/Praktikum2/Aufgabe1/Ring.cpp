/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

Ring::Ring() {
    this->numberOfNodes = 0;
    this->anker = nullptr;
}

int Ring::size() {
    if (this->anker == nullptr) {
        return 0;
    }

    RingNode *ptr = this->anker;
    int counter = 0;

    while(ptr->getNext() != this->anker) {
        counter++;
        ptr = ptr->getNext();
    }
    return counter + 1;
}

void findInsPlace() {

}

void Ring::incrementAge(){
    RingNode *node = this->anker;
    do{
        node->setAge(node->getAge() + 1);
        node = node->getNext();
    } while (node != this->anker);
}

RingNode* Ring::getNodeByAge(int age){
    RingNode *ptr = this->anker;

    while(ptr->getAge() != age)
        ptr = ptr->getNext();
    return ptr;
}


void Ring::addNode(std::string descr, std::string data) {
    RingNode *newNode = new RingNode;
    newNode->setNext(nullptr);
    newNode->setDescription(descr);
    newNode->setData(data);
    newNode->setAge(0);
    RingNode* node = this->anker;

    if (node) {
        incrementAge();
    }
    else {
        newNode->setNext(newNode);
        this->anker = newNode;
        this->numberOfNodes++;
        return;
    }

    if (this->numberOfNodes == 6) {

        RingNode *temp = node->getNext();
        node->setNext(newNode);
        newNode->setNext(temp->getNext());
        this->anker = newNode;
        delete temp;
    }
    else {
        node = this->getNodeByAge(1);

        newNode->setNext(node->getNext());
        node->setNext(newNode);
        this->anker = newNode;

        this->numberOfNodes++;
    }
    std::cout << "Hier: " << this->anker->getData();
}

bool Ring::search(std::string data){
    RingNode *ptr = this->anker;

    while(ptr->getNext() != this->anker) {
        if(ptr->getData() == data) {
            return true;
        }
        ptr = ptr->getNext();
    }

    return false;
}

void Ring::print(){
    if (this->anker == nullptr) {
        std::cout << "+ Keine Backups vorhanden." << std::endl << std::endl;
        return;
    }

    

    RingNode *ptr = this->anker;

    while(ptr->getNext() != this->anker) {
        std::cout << "OldAge: " << ptr->getAge() << ", Descr: " << ptr->getDescription() << ", Data: " << ptr->getData() << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        ptr =  ptr->getNext();
    }

    std::cout << "OldAge: " << ptr->getAge() << ", Descr: " << ptr->getDescription() << ", Data: " << ptr->getData() << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}
