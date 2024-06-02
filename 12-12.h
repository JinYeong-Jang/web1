// Created by 장진영 on 2024/05/30.
#ifndef TOP_SORT_12_12_H
#define TOP_SORT_12_12_H

#include "12-10.h"

class dAMGraph : public amGraph{
public:
    dAMGraph(int size, int initialValue =0): amGraph(size){}
    virtual void addEdge(int fromV, int toV);
};
#endif //TOP_SORT_12_12_H

void dAMGraph::addEdge(int fromV, int toV) {
    assert(fromV < n && toV < n && fromV >= 0 && toV >=0);
    if(!edgeMember(fromV,toV)){
        m++;
        am[fromV][toV] = 1;
    }
}