#include <bits/stdc++.h>
using namespace std;

// Prim's algorithm

vector<vector<int>> MST(vector<vector<pair<int, int>>> &graph){
    // {from, {to, weight}}
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<vector<int>> edges;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});
    // weight, node, parent
    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if(visited[node]) continue;
        visited[node] = 1;
        edges.push_back({parent, node});

        for(auto i : graph[node]){
            int neighbour = i.first;
            int w = i.second;

            if(!visited[neighbour]){
                pq.push({w, {neighbour, node}});
            }
        }
    }
    return edges;
    
}

int main(){

}