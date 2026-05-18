// Kahn's Algorithm / Topo Sort using BFS
// Step 1: Find out indegree of all vertices
// Step 2: Push all the nodes into queue with indegree 0
// Step 3: While q is not empty: pop out the front element, reduce indegree of all its adjacent vertices
// Step 4: If the indegree of any vertex becomes 0, push it into the queue again

#include <bits/stdc++.h>
using namespace std;

vector<int> linearOrdering(vector<vector<int>> &graph){
    int n = graph.size();
    queue<int> q;
    vector<int> order;
    vector<int> indegree(n, 0);
    for(auto i : graph){
        for(auto it : i){
            indegree[it]++;
        }
    }
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        order.push_back(node);
        for(auto adj : graph[node]){
            indegree[adj]--;
            if(indegree[adj] == 0) q.push(adj);
        }
    }
    return order;
}

int main(){
    
}