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

void Tree::deleteNode(int posID){

}

void Tree::depthPrint(TreeNode *node) {
    if(node == nullptr) {
        return;
    }

    node->print();

    depthPrint(node->getLeft());
    depthPrint(node->getRight());
}

void Tree::depthSearch(TreeNode *node, std::string name) {
    if (node == nullptr) {
        return;
    }

    if(node->getName() == name) {
        node->print();
    }

    depthSearch(node->getLeft(), name);
    depthSearch(node->getRight(), name);
}

bool Tree::searchNode(std::string name){
    if(this->anker == nullptr) {
        return false;
    }

    depthSearch(this->anker);
}

void Tree::printAll() {
    std::cout << "ID | Name               | Alter | Einkommen |  PLZ  | Pos   " << std::endl;
    std::cout << "---+--------------------+-------+-----------+-------+-------" << std::endl;

    depthPrint(this->anker);

    std::cout << std::endl;
}