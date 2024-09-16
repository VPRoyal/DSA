
// ----->>>>>>>>>>>>
// This is the definition of Kruskal's algorithm to find weight of minimum spanning tree.

#include <iostream>
#include <vector>
#include <algorithm>
#include "disjointSet.cpp"
#include "kruskalsAlgo.hpp"

using namespace std;
// Input must be in the format of {weight, firstNode, lastNode}
int findMSTreeWeight(vector<vector<int>>&edges, int numV){
    sort(edges.begin(), edges.end());
    DSU ds(numV);
    int mstWeight = 0;
    for(auto& edge : edges){
        int u = edge[1], v = edge[2];
        int p1=ds.find(u);
        int p2=ds.find(v);
        if(p1!=p2){
            ds.unite(u,v);
            mstWeight += edge[0];
            cout<<"Newly joined edge is: ("<<u<<","<<v<<")"<<endl;
        }
    }
    return mstWeight;
}