#include <bits/stdc++.h>
using namespace std;

class Disjoint_Set {
private:
    vector<int> rank;
    vector<int> parent;

public:
    Disjoint_Set(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if(parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]); // Path compression
    }

    void Union(int u, int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        // Already in same component
        if(ult_u == ult_v)
            return;

        // Union by rank
        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};