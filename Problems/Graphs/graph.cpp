// This namespace implements all basic functionality realted to Graph Data Structures.
/*
Test Case: vector<pair<int, int>> edges = {
            {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6},
            {3, 7}, {3, 8}, {4, 9}, {4, 10}, {5, 10}
        }
*/

#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <iostream>
#include "graph.hpp"
using namespace std;
namespace Graph
{
    // Creates Adjacency List for the Graph
    unordered_map<int, vector<int>> createADJ(const vector<pair<int, int>> &edges)
    {
        unordered_map<int, vector<int>> adjList;
        for (auto &edge : edges)
        {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first); // For Undirected Graph
        }
        return adjList;
    }
    // Function to perform Depth First Search (DFS)
    void BFS(int node, queue<int> &Nodes, const unordered_map<int, vector<int>> &adjList)
    {
        cout << node << " ";
        for (int neighbor : adjList.at(node))
            Nodes.push(neighbor);
    }
    void applyBFS(const unordered_map<int, vector<int>> &adjList)
    {
        unordered_map<int, bool> isVisited;
        queue<int> Nodes;
        for (auto it = adjList.begin(); it != adjList.end(); ++it)
        {
            if (!isVisited[it->first])
            {
                Nodes.push(it->first);
                cout<<"\nPrinting new component: first Element: "<<it->first<<endl;
                cout<<"BFS results: ";
                while (!Nodes.empty())
                {
                    int node = Nodes.front();
                    Nodes.pop();
                    if (!isVisited[node])
                    {
                        isVisited[node] = true;
                        BFS(node, Nodes, adjList);
                    }
                }
            }
        }
    }
    void DFS(int node, const unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &isVisited)
    {
        if (isVisited[node])
            return;
        cout << node << " ";
        isVisited[node] = true;
        for (int neighbor : adjList.at(node))
            DFS(neighbor, adjList, isVisited); // Recursive DFS call for neighbors of node.
    }
    void applyDFS(const unordered_map<int, vector<int>> &adjList)
    {
        unordered_map<int, bool> isVisited;
        for (auto &node : adjList)
            isVisited[node.first] = false;
        DFS(adjList.begin()->first, adjList, isVisited);
    }
}