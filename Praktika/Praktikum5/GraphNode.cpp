//
// Created by mauske on 27.06.19.
//

#include "GraphNode.h"

bool GraphNode::connectedTo(GraphNode *node) {
    for(int i = 0; i < this->getNumberOfEdges(); i++) {
        if(this->getEdge(i).endNode == node)
            return true;
    }

    return false;
}
