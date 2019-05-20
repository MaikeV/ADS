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
    TreeNode *newNode = new TreeNode(age + income*0.001 + plz, this->NodeIDCounter++, name, age, income, plz, true);
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

    if(parent == this->anker) {
        parent->getRight()->setRed(false);
        parent->getLeft()->setRed(false);
        return;
    }
    TreeNode *grandparent = findPreNode(this->anker, parent);
    TreeNode *uncle = nullptr;

    if(grandparent->getRight() == parent) {
        uncle = grandparent->getLeft();
    } else {
        uncle = grandparent->getRight();
    }

    if(parent->getRed() && uncle != nullptr) {
        if(uncle->getRed()) {
            uncle->setRed(false);
            parent->setRed(false);

            if(grandparent != this->anker) {
                grandparent->setRed(true);
            }
        }
    } else if (parent->getRed()) {
        if(parent->getRight() == newNode && grandparent->getLeft() == parent) {
            rotateTreeLeft(parent, newNode);
            rotateTreeRight(grandparent, newNode);
        } else if(parent->getLeft() == newNode && grandparent->getLeft() == parent) {
            rotateTreeRight(grandparent, parent);
        } else if(parent->getLeft() == newNode && grandparent->getRight() == parent) {
            rotateTreeRight(parent, newNode);
            rotateTreeLeft(grandparent, newNode);
        } else if(parent->getRight() == newNode && grandparent->getRight() == parent) {
            rotateTreeLeft(grandparent, parent);
        }
    }

    balanceTree();
}

bool Tree::rotateTreeLeft(TreeNode *nodeA, TreeNode *nodeB) {
    TreeNode *nodeC = nodeB->getRight();

    if(nodeA == this->anker) {
        this->anker = nodeB;

        if(nodeB->getLeft() != nullptr) {
            nodeA->setRight(nodeB->getLeft());
        } else {
            nodeA->setRight(nullptr);
        }

        nodeB->setLeft(nodeA);
        nodeB->setRed(false);
        nodeA->setRed(true);

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
        } else {
            nodeA->setRight(nullptr);
        }

        nodeB->setLeft(nodeA);
        nodeB->setRed(false);
        nodeA->setRed(true);

        return true;
    }

    return false;
}

bool Tree::rotateTreeRight(TreeNode *nodeA, TreeNode *nodeB) {
    TreeNode *nodeC = nodeB->getLeft();

    if(nodeA == this->anker) {
        if(nodeB->getRight() != nullptr) {
            nodeA->setLeft(nodeB->getRight());
        } else {
            nodeA->setLeft(nullptr);
        }

        this->anker = nodeB;

        nodeB->setRight(nodeA);
        nodeB->setRed(false);
        nodeA->setRed(true);

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
        } else {
            nodeA->setLeft(nullptr);
        }

        nodeB->setRight(nodeA);
        nodeB->setRed(false);
        nodeA->setRed(true);

        return true;
    }

    return false;
}

TreeNode* Tree::checkForTwoRed(TreeNode *start) {
    if(start == nullptr){
        return nullptr;
    } else if(start->getRed() && start->getRight() != nullptr) {
        if(start->getRight()->getRed())     return start->getRight();
    } else if(start->getRed() && start->getLeft() != nullptr) {
        if(start->getLeft()->getRed())      return start->getLeft();
    }

    checkForTwoRed(start->getLeft());
    checkForTwoRed(start->getRight());
}

bool Tree::balanceTree() {
    TreeNode *node = nullptr;
    TreeNode *parent = nullptr;

    do {
        node = checkForTwoRed(this->anker);

        if(node != nullptr && node != this->anker) {
            parent = findPreNode(this->anker, node);

            if(parent->getLeft() == node) {
                rotateTreeRight(parent, node);
            } else {
                rotateTreeLeft(parent, node);
            }
        }
    } while(node != nullptr);

    return true;
}

int Tree::getBlackHeight(TreeNode *start, int counter) {

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
