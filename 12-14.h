#ifndef TOP_SORT_12_14_H
#define TOP_SORT_12_14_H

#include "12-10.h"
class uAMGraph: public amGraph{
public:
    uAMGraph(int size, int initialValue =0): amGraph(size){}
    virtual void addEdge(int fromV, int toV);
};
#endif //TOP_SORT_12_14_H

void uAMGraph::addEdge(int fromV, int toV) {
    assert(fromV < n && toV < n && fromV >= 0 && toV >=0);
    if(!edgeMember(fromV, toV)){
        m++;
        am[fromV][toV] = 1;
        am[toV][fromV] = 1;
    }
}