//
// Created by mauske on 27.06.19.
//

#ifndef PRAKTIKUM5_GRAPHNODE_H
#define PRAKTIKUM5_GRAPHNODE_H

#include <vector>

class GraphNode {
public:
    struct edge {
        GraphNode* endNode;
        int weight;
    };

    GraphNode(int key) {
        this->visited = false;
        this->key = key;
    }

    int getKey() const {
        return key;
    }

    void setKey(int key) {
        GraphNode::key = key;
    }

    edge* getEdge(int value) {
        return &this->edges.at(value);
    }

    void addEdge(edge value) {
        this->edges.push_back(value);
    }

    int getNumberOfEdges() {
        return edges.size();
    }

    bool isVisited() const {
        return visited;
    }

    void setVisited(bool visited) {
        GraphNode::visited = visited;
    }

    int getComponent() const {
        return component;
    }

    void setComponent(int component) {
        GraphNode::component = component;
    }

private:
    int key;
    std::vector<edge> edges;
    bool visited;
    int component;
};


#endif //PRAKTIKUM5_GRAPHNODE_H
