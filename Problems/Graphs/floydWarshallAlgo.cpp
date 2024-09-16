#include <vector>
#include <math.h>
#include <iostream>
#include "floydWarshallAlgo.hpp"
using namespace std;
vector<vector<int>> calculateDistanceByFWA(vector<vector<int>> adjMatrix)
{
    for (int k = 0; k < adjMatrix.size(); k++)
    {
        for (int i = 0; i < adjMatrix.size(); i++)
        {
            for (int j = 0; j < adjMatrix.size(); j++)
            {
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }
    return adjMatrix;
}

// Function to print matrix values

void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}






/*
Test Case: 
std::vector<std::vector<int>> adjMatrix = {
    {0, 4, 2, INF, INF},  // Distances from node 0
    {4, 0, 1, 5, INF},    // Distances from node 1
    {2, 1, 0, 8, 10},     // Distances from node 2
    {INF, 5, 8, 0, 4},    // Distances from node 3
    {INF, INF, 10, 4, 0}  // Distances from node 4
};


 */