#include <bits/stdc++.h>
using namespace std;

bool detectCycleHelper(int src, vector<vector<int>> adj, vector<int>& visited){
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int u = q.front().first;
        int parent = q.front().second;

        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                q.push({v, u});
            }else{
                if(v != parent) return true;
            }
        }
    }
    return false;
}

bool detectCycle(vector<vector<int>> adj){
    vector<int> visited(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]){
            if(detectCycleHelper(i, adj, visited)) return true;
        }
        
    }

    return false;
} 

int main(){
    vector<vector<int>> adj = {
        {1}, {0, 2, 3}, {1}, {1, 4}, {3}
    };
    cout << detectCycle(adj);
    return 0;
}