#include <vector>
#include <math.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include "dijkstraAlgo.hpp"
using namespace std;

int calcDistanceBydijkstraAlgo(const unordered_map<int, vector<pair<int,int>>>& adjList, int start, int end, int numV){
    vector<int> distance(numV, INF);
    vector<bool> visited(numV, false);
    distance[start] = 0;
    priority_queue<pair<int,int>> nodes;
    nodes.push({0, start});
    
    while(!nodes.empty()){
        int current = nodes.top().second;
        nodes.pop();
        
        if(visited[current]) continue;
        visited[current] = true;
        
        // if(current == end) break;
        
        for(auto &neighbor : adjList.at(current)){
            int vertex = neighbor.first;
            int weight = neighbor.second;
            
            // if(!visited[neighbor_vertex] && distance[current] + weight < distance[neighbor_vertex]){
            //     distance[neighbor_vertex] = distance[current] + weight;
            //     nodes.push({distance[neighbor_vertex], neighbor_vertex});
            // }
            if(distance[current]+weight <distance[vertex]) distance[vertex] = distance[current]+weight;
            nodes.push({-distance[vertex], vertex});
        }
    }
    return distance[end];
}



/*
Test Case:
unordered_map<int, vector<pair<int, int>>> adjList = {
    {0, {{1, 4}, {2, 2}}},
    {1, {{0, 4}, {2, 1}, {3, 5}}},
    {2, {{0, 2}, {1, 1}, {3, 8}, {4, 10}}},
    {3, {{1, 5}, {2, 8}, {4, 4}}},
    {4, {{2, 10}, {3, 4}}}
};
*/