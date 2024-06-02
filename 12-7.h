//Directed Adjacency List Graph
// Created by 장진영 on 2024/05/27.
#ifndef RBT_12_7_H
#define RBT_12_7_H
#include "12-4.h"

class DALGraph : public ALGraph{
public:
    DALGraph(int size) : ALGraph(size){}
    virtual void addEdge(int fromV, int toV);
};

void
DALGraph::addEdge(int fromV, int toV)
{
    assert(fromV < n && fromV >=0 && toV <n && toV >=0);
    vertexList[fromV].insert(toV);
    m++;
}

#endif //RBT_12_7_H
