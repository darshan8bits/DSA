#include <bits/stdc++.h>
using namespace std;

// Floyd Warshall: DP approach to basically find shortest path lengths from
// every node to every other node, by minimizing cost via each intermediate node
// one by one. Runs in O(V^3)

vector<vector<int>> FloydWarshall(vector<vector<pair<int, int>>> &graph){
    int n = graph.size();
    vector<vector<int>> distance(n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++) distance[i][i] = 0;

    // update reachable nodes

    for(int i = 0; i < n; i++){
        int node = i;
        for(auto it : graph[node]){
            int neighbor = it.first;
            int weight = it.second;
            distance[node][neighbor] = weight;
        }
    }

    for(int via = 0; via < n; via++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(distance[i][via] == 1e9 || distance[via][j] == 1e9) continue;
                distance[i][j] = min(distance[i][j], distance[i][via] + distance[via][j]);
            }
        }
    }

    return distance;
}

int main(){

}