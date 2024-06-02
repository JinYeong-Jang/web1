#include <iostream>
#include <cassert>
#include <fstream>
#include "12-7.h"
#include "8-1.h"
#include "9-4.h"

using namespace std;
int main() {
    const char * inFileName = "/Users/jangjin-yeong/CLionProjects/Top_sort/graph.txt";

    ifstream ifs(inFileName);
    //assert(ifs);
    int n;
    if (!(ifs >> n)) {
        cerr << "Failed to read the number of vertices." << endl;
        return 2;
    }
    ifs >> n;
    cout << "Read n = " << n << endl;  // 이 라인을 추가하여 n이 제대로 읽히는지 확인

    DALGraph G(n);
    cout << "Created graph; n= " << G.vertexSize() << endl;
    int u, v;
    while(ifs >> u){
        ifs >> v;
        G.addEdge(u,v);
    }
    cout << "Edges in graph: m =" << G.edgeSize() << endl;
    int * vertices(new int[n]);
    assert(vertices);
    for(u=0; u<n; u++)
        vertices[u] = 0;
    for(u=0; u<n; u++){
        NeighborIter ni(G,u);
        while((v=++ni) != n)
            vertices[v]++;
    }
    Stack <int> s;
    for(u=0; u<n; u++)
        if(vertices[u]==0)
            s.push(u);
    if(s.isEmpty()){
        cout <<"graph has a cycle!\n";
        return 0;
    }
    int count = 0;
    Queue <int> sortedEdges;
    while(!s.isEmpty()){
        count++;
        u=s.pop();
        sortedEdges.enqueue(u);
        NeighborIter ni(G,u);
        while((v = ++ni) != n){
            --vertices[v];
            if(vertices[v]==0)
                s.push(v);
        }
    }
    if(count < n)
        cout << "Couldn;t complete top sort --c cycle present.\n";
    cout <<"Ordering for top sort: \n";
    while(!sortedEdges.isEmpty())
        cout << sortedEdges.dequeue() << '\t';
    cout << endl;
    return n;
}