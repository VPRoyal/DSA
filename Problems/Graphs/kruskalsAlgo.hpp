#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include <vector>

// Function to find the weight of the Minimum Spanning Tree (MST)
// Input: edges - a vector of edges in the format {weight, firstNode, lastNode}
//        numV - number of vertices in the graph
// Output: The weight of the Minimum Spanning Tree
int findMSTreeWeight(std::vector<std::vector<int>>& edges, int numV);

#endif // KRUSKAL_HPP
