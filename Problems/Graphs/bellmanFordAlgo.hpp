#ifndef CALCULATE_DISTANCE_BFA_HPP
#define CALCULATE_DISTANCE_BFA_HPP

#include <vector>
#include <tuple>  // For std::tuple
#include <math.h>

// Define INF in the header file to ensure consistency
const int INF = INT_MAX;

int calculateDistanceByBFA(const std::vector<std::tuple<int, int, int>>& edges, int start, int end, int numV);

#endif // CALCULATE_DISTANCE_BFA_HPP
