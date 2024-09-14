/* ----------------------------------------------------------------
Problem Statement: As another example, consider the following problem: Given an n × n grid whose each square is either black (1) or white (0), 
calculate the number of subgrids whose all corners are black.

Test Case:  grid={{0b01001, 0b01100, 0b10001, 0b11111, 0b10101}}
----------------------------------------------------------------
*/
#include <vector>
#include <bitset>
#include "countSubgrid.hpp"
using namespace std;
int countSubgrids(const vector<bitset<5>>& grid){
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = i+1; j < grid.size(); j++)
        {
            int c=(grid[i]&grid[j]).count()-1;
            if(c) count+=c;
        }
        
    }
    return count;
}
