// graph.hpp

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

namespace Graph {
    // Creates Adjacency List for the Graph
    unordered_map<int, vector<int>> createADJ(const vector<pair<int, int>>& edges);

    // Function to perform Breadth First Search (BFS)
    void BFS(int node, queue<pair<int,int>>& Nodes, const unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& isVisited);
    void applyBFS(const unordered_map<int, vector<int>>& adjList);

    // Function to perform Depth First Search (DFS)
    void DFS(int node, const unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& isVisited);
    void applyDFS(const unordered_map<int, vector<int>>& adjList);
}

#endif // GRAPH_HPP