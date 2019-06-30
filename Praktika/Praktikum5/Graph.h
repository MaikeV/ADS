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
    int numberOfKnots;
    bool ger;
    bool gew;
    std::vector<GraphNode*> nodes;

    GraphNode* getNodeByKey(int key);
    void setAllUnvisited();
    bool checkVisited();
    void startDepthSearchRek(GraphNode* node);
    bool testChildComponent(GraphNode* node);

public:
    Graph();
    ~Graph();

    bool init(std::string filepath);
    bool printAll();
    bool depthSearchRek(int startKey);
    bool breadthSearchIter(int startKey);
    double prim(int startKey);
    double kruskal();

    int getNumberOfKnots() const {
        return numberOfKnots;
    }
};


#endif //PRAKTIKUM5_GRAPH_H
