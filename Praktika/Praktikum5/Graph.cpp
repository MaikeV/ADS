//
// Created by mauske on 27.06.19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include "Graph.h"

GraphNode *Graph::getNodeByKey(int key) {
    return nullptr;
}

void Graph::setAllUnvisited() {
    for(int i = 0; i < this->numberOfNodes; i++) {
        this->nodes[i]->setVisited(false);
    }
}

bool Graph::checkVisited() {
    for(int i = 0; i < this->numberOfNodes; i++) {
        if(!this->nodes[i]->isVisited())
            return false;
    }
    return true;
}

bool Graph::testChildComponent(GraphNode *node) {
    return false;
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

        iss >> this->numberOfNodes;

        for(int i = 0; i < this->numberOfNodes; i++) {
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
                    for (int j = 0; j < this->numberOfNodes; j++) {
                        if (this->nodes[j]->getKey() == end) {
                            endNode = this->nodes[j];
                            break;
                        }
                    }

                    if (endNode) {
                        GraphNode::edge there;
                        GraphNode::edge andBackAgain;

                        there.startNode = this->nodes[i];
                        there.endNode = endNode;
                        there.weight = weight;

                        andBackAgain.startNode = endNode;
                        andBackAgain.endNode = this->nodes[i];
                        andBackAgain.weight = weight;

                        this->edges.push_back(there);
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
    for(int i = 0; i < this->numberOfNodes; i++) {
        std::cout << i;

        for(int j = 0; j < this->nodes[i]->getNumberOfEdges(); j++) {
            GraphNode::edge edge = this->nodes[i]->getEdge(j);

            std::cout << " -> " << edge.endNode->getKey() << " [" << edge.weight << "] ";
        }

        std::cout << std::endl;
    }

    return true;
}

bool Graph::depthSearchRek(int startKey) {
    this->setAllUnvisited();

    GraphNode* node = nullptr;

    for (int i = 0; i < this->numberOfNodes; i++)
        if(this->nodes[i]->getKey() == startKey) {
            node = this->nodes[i];
            break;
        }

    if(!node) {
        std::cout << "Key ist nicht in Graph enthalten" << std::endl << std::endl;
        return false;
    }

    startDepthSearchRek(node);

    return checkVisited();
}

void Graph::startDepthSearchRek(GraphNode *node) {
    node->setVisited(true);
    node->setComponent(node->getComponent() + 1);

    for(int i = 0; i < node->getNumberOfEdges(); i++)
        if (!node->getEdge(i).endNode->isVisited())
            startDepthSearchRek(node->getEdge(i).endNode);

}

bool Graph::breadthSearchIter(int startKey) {
    this->setAllUnvisited();

    GraphNode *node = nullptr;
    for (int i = 0; i < this->numberOfNodes; i++)
        if (this->nodes[i]->getKey() == startKey) {
            node = this->nodes[i];
            break;
        }

    if (!node) {
        std::cout << "Key ist nicht in Graph enthalten" << std::endl << std::endl;
        return false;
    }

    std::queue<GraphNode *> queue;
    queue.push(node);
    GraphNode *v = nullptr;

    while (!queue.empty() && !this->checkVisited()) {
        v = queue.front();
        queue.pop();

        v->setVisited(true);

        for (int i = 0; i < v->getNumberOfEdges(); i++) {
            if (!v->getEdge(i).endNode->isVisited()) {
                queue.push(v->getEdge(i).endNode);
            }
        }
    }

    return this->checkVisited();
}
//
//void visitNode(GraphNode *node, std::priority_queue<GraphNode::edge, std::vector<GraphNode::edge>, GraphNode::edge> &pq) {
//    node->setVisited(true);
//
//    for(int i = 0; i < node->getNumberOfEdges(); i++)
//        if(!node->getEdge(i).endNode->isVisited())
//            pq.push(node->getEdge(i));
//}

double Graph::prim(int startKey) {
    this->setAllUnvisited();

    if(startKey > this->numberOfNodes) {
        std::cout << "Key ist nicht in Graph enthalten" << std::endl << std::endl;
        return 0;
    }

    GraphNode* node = this->nodes[startKey];
    std::priority_queue<GraphNode::edge, std::vector<GraphNode::edge>, GraphNode::edge> pq;
    double costs = 0;

    for(int i = 0; i < node->getNumberOfEdges(); i++)
        if(!node->getEdge(i).endNode->isVisited())
            pq.push(node->getEdge(i));

//    visitNode(node, pq);

    while(!pq.empty()) {
        node->setVisited(true);

        if(!pq.top().endNode->isVisited()) {
            costs += pq.top().weight;
            node = pq.top().endNode;
            pq.pop();

            for(int i = 0; i < node->getNumberOfEdges(); i++)
                pq.push(node->getEdge(i));

        } else {
            pq.pop();
        }

//        GraphNode::edge edge = pq.top();
//        pq.pop();
//
//        int v = node->getKey();
//        int w = edge.endNode->getKey();
//
//        if(this->nodes[v]->isVisited() && this->nodes[w]->isVisited())
//            continue;
//
//        costs += edge.weight;
//
//        if(!nodes[v]->isVisited())
//            visitNode(this->nodes[v], pq);
//
//        if(!nodes[w]->isVisited())
//            visitNode(this->nodes[w], pq);
    }

    return costs;
}

double Graph::kruskal() {
    std::priority_queue<GraphNode::edge, std::vector<GraphNode::edge>, GraphNode::edge> pq;
    double costs = 0;

    for(int j = 0; j < this->edges.size(); j++) {
        pq.push(this->edges[j]);
    }

    for(int i = 0; i < this->numberOfNodes; i++) {
        this->nodes[i]->setComponent(i);
    }

    while(!pq.empty()) {
        GraphNode::edge edge = pq.top();
        pq.pop();

        GraphNode* startNode = edge.startNode;
        GraphNode* endNode = edge.endNode;

        if(startNode->getComponent() != endNode->getComponent()) {
            costs += edge.weight;

            int endComp = endNode->getComponent();
            for(int i = 0; i < this->nodes.size(); i++) {
                if(this->nodes[i]->getComponent() == endComp) {
                    this->nodes[i]->setComponent(startNode->getComponent());
                }
            }
        }
    }

    return costs;
}

