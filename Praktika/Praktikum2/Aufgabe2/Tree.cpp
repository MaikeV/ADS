/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>

void findPosByPosID(TreeNode *newNode, TreeNode *childNode) {
    if(newNode->getNodePosID() < childNode->getNodePosID()) {
        if(childNode->getLeft() != nullptr) {
            findPosByPosID(newNode, childNode->getLeft());
        } else {
            childNode->setLeft(newNode);
        }
    } else if(newNode->getNodePosID() > childNode->getNodePosID()) {
        if(childNode->getRight() != nullptr) {
            findPosByPosID(newNode, childNode->getRight());
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
            findPosByPosID(newNode, this->anker->getLeft());
        } else {
            this->anker->setRight(newNode);
            return;
        }
    } else if(newNode->getNodePosID() > this->anker->getNodePosID()) {
        if(this->anker->getRight() != nullptr) {
            findPosByPosID(newNode, this->anker->getRight());
        } else {
            this->anker->setRight(newNode);
            return;
        }
    } else {
        return;
    }
}

TreeNode* Tree::findMinOfRightSubTree(TreeNode *node) {

}

TreeNode* Tree::depthSearchByID(TreeNode *node, int posID) {
    if (node == nullptr) {
        return nullptr;
    }

    if(node->getNodePosID() == )

}

void Tree::deleteNode(int posID){
    if (this->anker == nullptr) {
        return;
    }

    TreeNode *min;

    if (this->anker->getNodePosID() == posID) {
        min = findMinOfRightSubTree(this->anker);

        if(min->getRight() == nullptr) {
            min->setRight(this->anker->getRight());
            min->setLeft(this->anker->getLeft());

            delete(this->anker);


        }

    } else if() {

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
    std::cout << "ID | Name               | Alter | Einkommen |  PLZ  | Pos   " << std::endl;
    std::cout << "---+--------------------+-------+-----------+-------+-------" << std::endl;

    depthPrint(this->anker);

    std::cout << std::endl;
}