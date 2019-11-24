//
// Created by mauske on 27.06.19.
//

#ifndef PRAKTIKUM5_GRAPH_H
#define PRAKTIKUM5_GRAPH_H

#include "GraphNode.h"
#include <vector>
#include <string>

class Graph {
private:
    int numberOfNodes;
    bool ger;
    bool gew;
    std::vector<GraphNode*> nodes;
    std::vector<GraphNode::edge> edges;

private:

    GraphNode* getNodeByKey(int key);
    void setAllUnvisited();
    bool checkVisited();
    void startDepthSearchRek(GraphNode* node);
    bool testChildComponent(GraphNode* node);

public:
    Graph() {
        this->ger = false;
        this->gew = true;
        this->numberOfNodes = 0;
    }

    ~Graph() {
        nodes.~vector();
    }

    bool init(std::string filepath);
    bool printAll();
    bool depthSearchRek(int startKey);
    bool depthSearchIter(int startKey);
    bool breadthSearchIter(int startKey);
    double prim(int startKey);
    double kruskal();

    int getNumberOfNodes() const {
        return numberOfNodes;
    }
};


#endif //PRAKTIKUM5_GRAPH_H
