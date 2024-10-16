
// #include "disjointSet.hpp"

// This is the implementation of Disjoint Set data structure.
class DSU {
 int* parent;
 int* rank;
 public:
    DSU(int n){
        parent =new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        };
    };
    ~DSU() {
        delete[] parent;
        delete[] rank;
    };

    int find(int n){
        if(parent[n] == n) return n;
        // Path compression by making the parent of the found node as the root
        return parent[n] = find(parent[n]);
    }
    void unite(int x, int y){
        int p1=find(x);
        int p2=find(y);
        if(p1 != p2){
            if(rank[p1]<rank[p2]) parent[p1] = p2;
            else if(rank[p1]>rank[p2]) parent[p2] = p1;
            else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
};
