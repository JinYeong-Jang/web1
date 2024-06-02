// Created by 장진영 on 2024/05/23.
#ifndef RBT_12_1_H
#define RBT_12_1_H

class graph{
public:
    graph(int size) : n(size), m(0){}
    virtual int vertexSize() { return n;}
    virtual int edgeSize() {return m;}
    virtual void addEdge(int fromV, int toV) =0; //specify abstract class (pure virtual 함수 선언)
    //다른 class마다 다른 함수기능을 구현할 때 사용함
protected:
    int n; // number of vertices
    int m; // number of edges
};
#endif //RBT_12_1_H
