/*
Statement: This is Bellman Ford algorithm which is used to calculate shortest distance between two nodes in a graph
Test Cases 1: vector<tuple<int, int, int>> edges1 = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, 8},
        {2, 4, 10},
        {3, 4, 3}
}
 */
#include <vector>
#include <math.h>
#include <iostream>
#include "bellmanFordAlgo.hpp"
using namespace std;
int calculateDistanceByBFA(const vector<tuple<int,int, int>>& edges, int start, int end, int numV){
    int count=0;
    vector<int> distance(numV, INF);
    distance[start]=0;
    for(int i=1;i<=numV-1;i++){
        // Adding this "change" check will improves the efficiency, because function will exit if,
        // no changes are made, so that it will not run for all cases.
        int change=0;
        for(auto& edge: edges){
            int f,s,w;
            tie(f,s,w)=edge;
            int minValue=min(distance[s],distance[f]+w);
            if(minValue!=distance[s]) change++;
            distance[s]=minValue;
            count++;
        }
        if(change==0) break;
    }
    cout<<"Total count: "<<count<<endl;
    return distance[end];
}