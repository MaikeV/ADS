#pragma once
#include <string>

class TreeNode{
private:
    int nodePosID;
    int nodeID;
    bool red;
    std::string name;
    int age;
    double income;
    int plz;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(int nodePosID, int nodeID, std::string name, int age, double income, int plz, bool red){
        this->nodePosID = nodePosID;
        this->nodeID = nodeID;
        this->name = name;
        this->age = age;
        this->income = income;
        this->plz = plz;
        this->left = nullptr;
        this->right = nullptr;
        this->red = red;
    }

    void print();
    double calcNodePosID(int age, int plz, double income);

    int getNodePosID() const {
        return nodePosID;
    }

    void setNodePosID(int nodePosId) {
        nodePosID = nodePosId;
    }

    int getNodeID() const {
        return nodeID;
    }

    void setNodeID(int nodeId) {
        nodeID = nodeId;
    }

    bool getRed() const {
        return red;
    }

    void setRed(bool red) {
        TreeNode::red = red;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        TreeNode::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        TreeNode::age = age;
    }

    double getIncome() const {
        return income;
    }

    void setIncome(double income) {
        TreeNode::income = income;
    }

    int getPLZ() const {
        return plz;
    }

    void setPLZ(int plz) {
        TreeNode::plz = plz;
    }

    TreeNode *getLeft() const {
        return left;
    }

    void setLeft(TreeNode *left) {
        TreeNode::left = left;
    }

    TreeNode *getRight() const {
        return right;
    }

    void setRight(TreeNode *right) {
        TreeNode::right = right;
    }
};
