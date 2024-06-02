// Header for adjacency list base class
// Created by 장진영 on 2024/05/27.
#ifndef RBT_12_4_H
#define RBT_12_4_H
#include "12-1.h"
#include "12-2.h"

typedef  List <int> IntList;
typedef ListIter <int> IntListIter;

class ALGraph : public graph{
public:
    ALGraph(int size) : graph(size)
    {vertexList = new IntList[n]; assert(vertexList);}
    friend  class NeighborIter;
protected:
    IntList * vertexList;
};

class NeighborIter : public IntListIter {
public:
    NeighborIter(const ALGraph&G, int startVertex):
            IntListIter(G.vertexList[startVertex],G.n){assert(startVertex < G.n);}
};
#endif //RBT_12_4_H
