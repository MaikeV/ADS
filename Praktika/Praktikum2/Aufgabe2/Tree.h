/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

class Tree{
	
	private: 
		TreeNode *anker;
		int NodeIDCounter;
	public:
		Tree(){
		    this->anker = nullptr;
		    this->NodeIDCounter = 0;
		}

		void addNode(std::string name, int age, double income, int plz);
		void deleteNode(int posID);
		bool searchNode(std::string name);
		void printAll();
		void depthPrint(TreeNode *node);
		void depthSearchByName(TreeNode *node, std::string name, bool &found);
		TreeNode* depthSearchByID(TreeNode *node, int posID);
		TreeNode* findMinOfRightSubTree(TreeNode *node);

		friend TreeNode * get_anker(Tree& TN);
};
