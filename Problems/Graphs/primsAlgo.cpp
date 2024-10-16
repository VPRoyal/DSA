#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
using namespace std;

class PrimsAlgo
{
    vector<bool> visited; // Using vector<bool> for visited array
    unordered_map<int, vector<pair<int, int>>>* nodes;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> queue; // Min-heap priority_queue
    int weight = 0;
public:
    vector<pair<int,int>> MST;
    PrimsAlgo(unordered_map<int,vector<pair<int,int>>>& nodes, int numV): nodes(&nodes), visited(numV+1,false) {};
    int calculateWeight(){
        auto it=nodes->begin();
        int w=0, vertex = it->first, parent=-1;
        queue.emplace(make_tuple(w, vertex, parent));
        while(!queue.empty()){
            tie(w, vertex, parent) = queue.top();
            queue.pop();
            if(!visited[vertex]){
                visited[vertex]=true;
                weight+=w;
                if(parent!=-1) MST.push_back({parent,vertex});
            for(auto& node: nodes->at(vertex)){
                if(visited[node.first]) continue;
                queue.emplace(make_tuple(node.second, node.first, vertex));
            }
        }
        }
        return weight;
    }
};

int main(){
    unordered_map<int, vector<pair<int, int>>> adjList = {
    {1, {{2, 7}, {3, 9}, {4, 10}}},        
    {2, {{1, 7}, {3, 10}, {5, 15}}},       
    {3, {{1, 9}, {2, 10}, {4, 11}, {6, 2}}},
    {4, {{1, 10}, {3, 11}, {5, 6}}},       
    {5, {{2, 15}, {4, 6}, {6, 9}}},        
    {6, {{3, 2}, {5, 9}}}            
    };
    
    PrimsAlgo prims(adjList, 6);
    cout<<"Weight of MST is: "<<prims.calculateWeight()<<endl;
    cout<<"MST: "<<endl;
    for(auto& edge: prims.MST){
        cout<<edge.first<<" - "<<edge.second<<endl;
    }
    return 0;
}