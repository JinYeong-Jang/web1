// Header for undirected Adjacency List graphs
// Created by 장진영 on 2024/05/27.

#ifndef RBT_12_5_H
#define RBT_12_5_H

#include "12-4.h"
class UALGraph : public ALGraph{
public:
    UALGraph(int size) : ALGraph(size){}
    virtual void addEdge(int fromV, int toV);
};
#endif //RBT_12_5_H

void UALGraph::addEdge(int fromV, int toV){
    assert(fromV < n && fromV >=0 && toV <n && toV >=0);
    vertexList[fromV].insert(toV);
    vertexList[toV].insert(fromV);
    m++;
}