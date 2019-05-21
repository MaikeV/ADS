#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

class Tree{

private:
    TreeNode *anker;
    int NodeIDCounter;

    bool rotateTreeRight(TreeNode *nodeA, TreeNode *nodeB);
    bool rotateTreeLeft(TreeNode *nodeA, TreeNode *nodeB);
public:
    Tree(){
        this->anker = nullptr;
        this->NodeIDCounter = 0;
    }

    void addNode(std::string name, int age, double income, int plz);
    bool searchNode(std::string name);
    void printAll();
    void depthSearchByName(TreeNode *node, std::string name, bool &found);
    TreeNode* depthSearchByID(TreeNode *node, int posID);
    TreeNode* findMin(TreeNode *node);
    TreeNode* findPreNode(TreeNode *node, TreeNode *child);
    void readFromCsv();
    void printLevelOrder();
    bool balanceTree();
    void depthPrint(TreeNode *node);

    TreeNode* checkForTwoRed(TreeNode *start);

    friend TreeNode * get_anker(Tree& TN);
};
