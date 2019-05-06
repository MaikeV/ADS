/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void Tree::readFromCsv() {
    std::ifstream file("/home/mauske/Studium/ADS/ADS/Praktika/Praktikum2/Aufgabe2/ExportZielanalyse.csv");

    std::string line;
    std::string str[4];

    //name;age;income;plz

    while(std::getline(file, line)) {
        int j = 0;
        int last = -1;
        for(int i = 0; i < line.size(); i++) {
            if(line.at(i) == ';') {
                str[j] = line.substr(last + 1, i - last - 1);

                j++;
                last = i;
            }
        }
        str[j] = line.substr(last + 1, line.size() - last - 1);

        this->addNode(str[0], std::stoi(str[1]), std::stod(str[2]), std::stoi(str[3]));
    }
}

void addAtPos(TreeNode *newNode, TreeNode *childNode) {
    if(newNode->getNodePosID() < childNode->getNodePosID()) {
        if(childNode->getLeft() != nullptr) {
            addAtPos(newNode, childNode->getLeft());
        } else {
            childNode->setLeft(newNode);
        }
    } else if(newNode->getNodePosID() > childNode->getNodePosID()) {
        if(childNode->getRight() != nullptr) {
            addAtPos(newNode, childNode->getRight());
        } else{
            childNode->setRight(newNode);
        }
    }
}

void Tree::addNode(std::string name, int age, double income, int plz){
    TreeNode *newNode = new TreeNode(age + income + plz, this->NodeIDCounter++, name, age, income, plz);
    newNode->setLeft(nullptr);
    newNode->setRight(nullptr);

    if (this->anker == nullptr) {
        this->anker = newNode;
        return;
    }

    if(newNode->getNodePosID() < this->anker->getNodePosID()) {
        if(this->anker->getLeft() != nullptr) {
            addAtPos(newNode, this->anker->getLeft());
        } else {
            this->anker->setLeft(newNode);
            return;
        }
    } else if(newNode->getNodePosID() > this->anker->getNodePosID()) {
        if(this->anker->getRight() != nullptr) {
            addAtPos(newNode, this->anker->getRight());
        } else {
            this->anker->setRight(newNode);
            return;
        }
    } else {
        return;
    }
}

TreeNode* Tree::findMin(TreeNode *node) {
    if(node->getLeft() == nullptr) {
        return node;
    }

    findMin(node->getLeft());
}

TreeNode* Tree::depthSearchByID(TreeNode *node, int posID) {
    if(node->getNodePosID() == posID) {
        return node;
    }

    if(node->getNodePosID() > posID) {
        depthSearchByID(node->getLeft(), posID);
    } else {
        depthSearchByID(node->getRight(), posID);
    }
}

TreeNode* Tree::findPreNode(TreeNode *node, TreeNode *child) {
    if(node->getLeft() == child || node->getRight() == child) {
        return node;
    }

    if(node->getNodePosID() > child->getNodePosID()) {
        findPreNode(node->getLeft(), child);
    } else if(node->getNodePosID() < child->getNodePosID()) {
        findPreNode(node->getRight(), child);
    }
}

void Tree::deleteNode(int posID){
    if (this->anker == nullptr) {
        return;
    }

    TreeNode *min;
    TreeNode *temp;

    //if anchor node
    if (this->anker->getNodePosID() == posID) {
        if(!this->anker->getLeft() && !this->anker->getRight()){
            this->anker = nullptr;
            return;
        } else if(!this->anker->getRight()){
            if(this->anker->getLeft()){
                temp = this->anker->getLeft();
                this->anker = temp;
                return;
            }
            this->anker = nullptr;
        }

        min = findMin(this->anker->getRight());
        temp = findPreNode(this->anker, min);

        if(min->getRight() != nullptr && temp != this->anker) {
            temp->setLeft(min->getRight());
        } else {
            if(temp->getRight() == min) {
                if(temp == this->anker)
                    temp->setRight(min->getRight());
                else
                    temp->setRight(nullptr);
            } else if(temp->getLeft() == min) {
                temp->setLeft(nullptr);
            }
        }

        min->setRight(this->anker->getRight());
        min->setLeft(this->anker->getLeft());
        this->anker = min;

        return;
    }

    TreeNode *toDel = depthSearchByID(this->anker, posID);
    TreeNode *pre = findPreNode(this->anker, toDel);

    //if no child nodes
    if(toDel->getRight() == nullptr && toDel->getLeft() == nullptr) {
        if(pre->getLeft() == toDel) {
            pre->setLeft(nullptr);
        } else if(pre->getRight() == toDel) {
            pre->setRight(nullptr);
        }

        toDel = nullptr;

        return;
    } else if (toDel->getRight() != nullptr && toDel->getLeft() != nullptr) { // if 2 child nodes
        min = findMin(toDel->getRight());
        temp = findPreNode(this->anker, min);

        if(min->getRight() != nullptr) {
            temp->setLeft(min->getRight());
        } else {
            if(temp->getRight() == min) {
                temp->setRight(nullptr);
            } else if(temp->getLeft() == min) {
                temp->setLeft(nullptr);
            }
        }

        if(pre->getRight() == toDel) {
            pre->setRight(min);
        } else if(pre->getLeft() == toDel) {
            pre->setLeft(min);
        }

        min->setRight(toDel->getRight());
        min->setLeft(toDel->getLeft());

        toDel = nullptr;

        return;
    } else if (toDel->getRight() != nullptr || toDel->getLeft() != nullptr) { // if 1 child node


        if(toDel->getLeft() != nullptr) {
            if(pre->getLeft() == toDel) {
                pre->setLeft(toDel->getLeft());
            } else {
                pre->setRight(toDel->getLeft());
            }
        } else if (toDel->getRight() != nullptr){
            if(pre->getLeft() == toDel) {
                pre->setLeft(toDel->getRight());
            } else if (pre->getRight() == toDel) {
                pre->setRight(toDel->getRight());
            }
        }

        toDel = nullptr;
        return;
    }
}

void Tree::depthSearchByName(TreeNode *node, std::string name, bool &found) {
    if (node == nullptr) {
        return;
    }

    if(node->getName() == name) {
        std::cout << "NodeID: " << node->getNodeID() << ", Name: " << node->getName() << ", Alter: " << node->getAge() << ", Einkommen: " << node->getIncome() << ", PLZ: " << node->getPLZ() << ", PosID: " << node->getNodePosID() << std::endl;
        found = true;
    }

    depthSearchByName(node->getLeft(), name, found);
    depthSearchByName(node->getRight(), name, found);
}

bool Tree::searchNode(std::string name){
    if(this->anker == nullptr) {
        return false;
    }

    bool found = false;

    depthSearchByName(this->anker, name, found);

    return found;
}

void Tree::depthPrint(TreeNode *node) {
    if(node == nullptr) {
        return;
    }

    node->print();

    depthPrint(node->getLeft());
    depthPrint(node->getRight());
}

void Tree::printAll() {
    std::cout << "ID | Name               | Alter | Einkommen          | PLZ                | Pos                " << std::endl;
    std::cout << "---+--------------------+-------+--------------------+--------------------+--------------------" << std::endl;

    depthPrint(this->anker);

    std::cout << std::endl;
}