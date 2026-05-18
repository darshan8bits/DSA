#include <bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>> adj, vector<int> &visited, int curr, int parent){
    visited[curr] = 1;
    for(auto v : adj[curr]){
        if(!visited[v]){
            if(detectCycle(adj, visited, v, curr)) return true;
        }else{
            if(v != parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> adj){
    vector<int> visited(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]){
            if(detectCycle(adj, visited, i, -1)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adj = {
        {1}, {0, 2, 3}, {1}, {1, 4}, {3}
    };
    return 0;
}