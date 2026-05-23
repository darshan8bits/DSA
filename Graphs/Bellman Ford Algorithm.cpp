#include <bits/stdc++.h>
using namespace std;

// Bellman Ford, like dijkstra, but relax each 'edge' n - 1
// times, then check for a negative cycle in the next iteration.

bool BellmanFord(vector<vector<pair<int, int>>> &graph, int source, vector<int> &distance){
    // graph format: node -> {[neighbour, weight], [], [], ....}
    // edges format: {from, to, weight}
    
    int n = graph.size();
    for(int i = 0; i < n; i++) distance[i] = 1e9;
    vector<vector<int>> edges;
    for(int node = 0; node < n; node++){
        for(auto& [neighbour, weight] : graph[node]){
            edges.push_back({node, neighbour, weight});
        }
    }

    // relax each edge n - 1 times:
    distance[source] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            int weight = edges[j][2];
            int v = edges[j][1];
            int u = edges[j][0];

            if(distance[u] == 1e9) continue;

            int newdistance = distance[u] + weight;
            if(newdistance < distance[v]){
                distance[v] = newdistance;
            }
        }
    }

    for(int i = 0; i < edges.size(); i++){
            int weight = edges[i][2];
            int v = edges[i][1];
            int u = edges[i][0];

            int newdistance = distance[u] + weight;
            if(newdistance < distance[v]){
                return false;
            }
    }

    return true;

}

int main(){

}
