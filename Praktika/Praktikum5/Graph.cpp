//
// Created by mauske on 27.06.19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "Graph.h"

GraphNode *Graph::getNodeByKey(int key) {
    return nullptr;
}

void Graph::setAllUnvisited() {

}

bool Graph::checkVisited() {
    return false;
}

void Graph::startDepthSearchRek(GraphNode *node) {

}

bool Graph::testChildComponent(GraphNode *node) {
    return false;
}

Graph::Graph() {

}

Graph::~Graph() {

}

bool Graph::init(std::string filepath) {
    std::ifstream file;

    file.open(filepath, std::ios_base::in);

    if (!file) {
        std::cout << "Cannot open file" << std::endl << std::endl;
        return false;
    } else {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);

        iss >> this->numberOfKnots;

        for(int i = 0; i < this->numberOfKnots; i++) {
            GraphNode* newNode = new GraphNode(i);

            this->nodes.push_back(newNode);
        }

        while(std::getline(file, line)) {
            //Start End Weight

            int pos1 = line.find(' ');
            int pos2 = line.find(' ', pos1 + 1);
            int pos3 = line.find('\r');

            int start = std::stoi(line.substr(0, pos1));
            int end = std::stoi(line.substr(pos1 + 1, pos2 - (pos1 + 1)));
            int weight = std::stoi(line.substr(pos2 + 1, pos3 - (pos2 + 1)));

            GraphNode *endNode = nullptr;

            for (int i = 0; i < this->nodes.size(); i++) {
                if(this->nodes[i]->getKey() == start) {
                    for (int j = 0; j < this->numberOfKnots; j++) {
                        if (this->nodes[j]->getKey() == end) {
                            endNode = this->nodes[j];
                            break;
                        }
                    }

                    if (endNode) {
                        GraphNode::edge there;
                        GraphNode::edge andBackAgain;

                        there.endNode = endNode;
                        there.weight = weight;

                        andBackAgain.endNode = this->nodes[i];
                        andBackAgain.weight = weight;

                        this->nodes[i]->addEdge(there);
                        endNode->addEdge(andBackAgain);
                        break;
                    }
                }
            }
        }

        return true;
    }
}

bool Graph::printAll() {
    for(int i = 0; i < this->numberOfKnots; i++) {
        std::cout << i;

        for(int j = 0; j < this->nodes[i]->getNumberOfEdges(); j++) {
            GraphNode::edge* edge = this->nodes[i]->getEdge(j);

            std::cout << " -> " << edge->endNode->getKey() << " [" << edge->weight << "] ";
        }

        std::cout << std::endl;
    }

    return true;
}

bool Graph::depthSearchRek(int startKey) {
    return false;
}

bool Graph::breadthSearchIter(int startKey) {
    return false;
}

double Graph::prim(int startKey) {
    return 0;
}

double Graph::kruskal() {
    return 0;
}
