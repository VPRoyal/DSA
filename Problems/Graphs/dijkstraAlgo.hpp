#ifndef DIJKSTRA_ALGO_HPP
#define DIJKSTRA_ALGO_HPP

#include <vector>
#include <unordered_map>
#include <utility> // for std::pair

// Define INF in the header file to ensure consistency
const int INF = INT_MAX;
// Function to calculate the shortest distance using Dijkstra's algorithm
int calcDistanceBydijkstraAlgo(const std::unordered_map<int, std::vector<std::pair<int, int>>>& adjList, int start, int end, int numV);

#endif // DIJKSTRA_ALGO_HPP
