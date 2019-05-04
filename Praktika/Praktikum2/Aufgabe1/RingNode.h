/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	int age;
	std::string description;
	std::string data;
	RingNode *next;
public:
	RingNode(){}
	RingNode(int age, std::string description, std::string data) {
	    this->age = age;
	    this->description = description;
	    this->data = data;
	}

    int getAge() const {
        return age;
    }

    void setAge(int age) {
	    this->age = age;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        this->description = description;
    }

    const std::string &getData() const {
        return data;
    }

    void setData(const std::string &data) {
        this->data = data;
    }

    RingNode *getNext() const {
        return next;
    }

    void setNext(RingNode *next) {
        this->next = next;
    }
};
