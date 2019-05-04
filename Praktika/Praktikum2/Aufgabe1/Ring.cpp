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

void Ring::addNode(std::string descr, std::string data) {
    RingNode *newEntry = new RingNode;
    newEntry->setNext(nullptr);
    newEntry->setDescription(descr);
    newEntry->setData(data);
    newEntry->setAge(0);

    if (this->anker == nullptr) {
        this->anker = newEntry;
        newEntry->setNext(this->anker);

        this->numberOfNodes++;
        return;
    }

    if (size() < 6) {
        RingNode *ptr = this->anker;

        this->anker = newEntry;
        newEntry->setNext(ptr);

        while (ptr->getNext() != this->anker->getNext()) {
            ptr->setAge(ptr->getAge() + 1);
            ptr = ptr->getNext();
        }

        ptr->setAge(ptr->getAge() + 1);
        //ptr->setNext(this->anker);

        this->numberOfNodes++;
        return;
    }

    if (size() == 6) {
        RingNode *ptr = this->anker;
        RingNode *temp;

        while (ptr->getNext() != this->anker) {
            if (ptr->getNext()->getAge() == 5) {
                temp = ptr->getNext()->getNext();

                ptr->setNext(newEntry);
                newEntry->setNext(temp);

                break;
            }
            ptr = ptr->getNext();
        }

        temp = this->anker;

        this->anker = ptr->getNext();
        ptr->getNext()->setNext(temp);

        ptr = ptr->getNext()->getNext();

        while (ptr->getNext() != this->anker) {
            ptr->setAge(ptr->getAge() + 1);
            ptr = ptr->getNext();
        }

        ptr->setAge(ptr->getAge() + 1);
        return;
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
        std::cout << "+ Keine Backups vorhanden.";
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
