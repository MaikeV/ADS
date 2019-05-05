/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.hpp"
#include"RingNode.h"

class Ring {
	private:
        int numberOfNodes;
        RingNode *anker;
	public:
        Ring();

        void setNumberOfNodes(int numberOfNodes) {
            Ring::numberOfNodes = numberOfNodes;
        }

        void setAnker(RingNode *anker) {
            Ring::anker = anker;
        }

        void addNode(std::string descr, std::string data);
        bool search(std::string data);
        void print();
        int size();
        void incrementAge();
        RingNode* getNodeByAge(int age);

        // friend Funktionen muessen unangetastet bleiben!
        friend RingNode * get_anker(Ring& r);
        friend int get_AnzahlNodes(Ring& r);
};
