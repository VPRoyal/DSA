#ifndef FLOYD_WARSHALL_ALGO_HPP
#define FLOYD_WARSHALL_ALGO_HPP

#include <vector>

// Function to calculate the shortest paths using Floyd-Warshall algorithm
std::vector<std::vector<int>> calculateDistanceByFWA(std::vector<std::vector<int>> adjMatrix);
void printMatrix(std::vector<std::vector<int>> matrix);

#endif // FLOYD_WARSHALL_ALGO_HPP
