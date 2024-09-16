#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP

class DSU {
    int* parent;
    int* rank;

public:
    // Constructor to initialize the DSU with n elements
    explicit DSU(int n);

    // Destructor to clean up dynamically allocated memory
    ~DSU();

    // Find the representative (root) of the set containing element n
    int find(int n);

    // Unite the sets containing elements x and y
    void unite(int x, int y);
};

#endif // DISJOINTSET_HPP
