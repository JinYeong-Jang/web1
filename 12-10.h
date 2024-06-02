// Created by 장진영 on 2024/05/30.
#ifndef TOP_SORT_12_10_H
#define TOP_SORT_12_10_H
#include <cassert>
#include "12-1.h"

class amGraph : public graph{
public:
    amGraph(int size);
    virtual bool edgeMember(int fromV, int toV);
protected:
    int * *am;
};
#endif //TOP_SORT_12_10_H

amGraph::amGraph(int size) : graph(size)
{
    int i;
    am = new int * [n];
    assert(am);
    for(i=0; i<n; i++){
        am[i]=new int[n];
        assert(am[i]);
        int j;
        for(j=0;j<n;j++)
            am[i][j]=0;
    }
}

bool amGraph::edgeMember(int fromV, int toV){
    assert(fromV < n && toV < n && fromV >= 0 && toV >=0);
    return bool(am[fromV][toV] != 0);
}