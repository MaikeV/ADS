#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

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
    TreeNode *newNode = new TreeNode(age + income + plz, this->NodeIDCounter++, name, age, income, plz, true);
    newNode->setLeft(nullptr);
    newNode->setRight(nullptr);

    if (this->anker == nullptr) {
        newNode->setRed(false);
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

    TreeNode *parent = findPreNode(this->anker, newNode);
    TreeNode *grandparent = findPreNode(this->anker, parent);
    TreeNode *uncle = nullptr;

    if(grandparent->getRight() == parent) {
        uncle = grandparent->getLeft();
    } else {
        uncle = grandparent->getRight();
    }

    if(parent->getRed() && uncle->getRed()) {
        uncle->setRed(false);
        parent->setRed(false);

        if(grandparent != this->anker) {
            grandparent->setRed(true);
        }
    } else if (parent->getRed() && !uncle->getRed()) {
        if(parent->getRight() == newNode && grandparent->getLeft() == parent) {
            rotateTreeLeft(parent, newNode);
            rotateTreeRight(grandparent, parent);
        } else if(parent->getLeft() == newNode && grandparent->getLeft() == parent) {
            rotateTreeRight(grandparent, parent);
        } else if(parent->getLeft() == newNode && grandparent->getRight() == parent) {
            rotateTreeRight(parent, newNode);
            rotateTreeLeft(grandparent, parent);
        } else if(parent->getRight() == newNode && grandparent->getRight() == parent) {
            rotateTreeLeft(grandparent, parent);
        }
    }
}

bool Tree::rotateTreeLeft(TreeNode *nodeA, TreeNode *nodeB) {
    TreeNode *nodeC = nodeB->getRight();

    if(nodeA == this->anker) {
        this->anker = nodeB;

        if(nodeB->getLeft() != nullptr) {
            nodeA->setRight(nodeB->getLeft());
        }

        nodeB->setLeft(nodeA);

        return true;
    } else {
        TreeNode *parent = findPreNode(this->anker, nodeA);

        if (parent->getLeft() == nodeA) {
            parent->setLeft(nodeB);
        } else {
            parent->setRight(nodeB);
        }

        if (nodeB->getLeft() != nullptr) {
            nodeA->setRight(nodeB->getLeft());
        }

        nodeB->setLeft(nodeA);

        return true;
    }

    return false;
}

bool Tree::rotateTreeRight(TreeNode *nodeA, TreeNode *nodeB) {
    TreeNode *nodeC = nodeB->getLeft();

    if(nodeA == this->anker) {
        this->anker = nodeB;

        if(nodeB->getRight() != nullptr) {
            nodeA->setLeft(nodeB->getRight());
        }

        nodeB->setRight(nodeA);

        return true;
    } else {
        TreeNode *parent = findPreNode(this->anker, nodeA);

        if(parent->getLeft() == nodeA) {
            parent->setLeft(nodeB);
        } else {
            parent->setRight(nodeB);
        }

        if(nodeB->getRight() != nullptr) {
            nodeA->setLeft(nodeB->getRight());
        }

        nodeB->setRight(nodeA);

        return true;
    }

    return false;
}

bool Tree::balanceTree() {


    return false;
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

void Tree::printAll() {
    printLevelOrder();
}

void Tree::printLevelOrder() {
    std::cout << "ID | Name               | Alter | Einkommen          | PLZ                | Pos                | Red      " << std::endl;
    std::cout << "---+--------------------+-------+--------------------+--------------------+--------------------+----------" << std::endl;

    TreeNode *ptr = 0;

    std::queue<TreeNode*> queue;
    queue.push(this->anker);

    while(!queue.empty()){
        ptr = queue.front();
        queue.pop();
        ptr->print();

        if(ptr->getLeft())  queue.push(ptr->getLeft());
        if(ptr->getRight()) queue.push(ptr->getRight());
    }

    std::cout << std::endl;
}
