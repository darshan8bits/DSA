// Detect Cycle in a Directed Graph using DFS
// Cycle detection for Undirected Graph does not work!

#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>> &graph, int node, vector<int> &visited, vector<int> &pathvisited){
    visited[node] = 1;
    pathvisited[node] = 1;

    for(auto it : graph[node]){
        if(!visited[it]){
            if(dfsCycle(graph, it, visited, pathvisited)) return true;
        }else{
            if(pathvisited[it]) return true;
        }
    }
    pathvisited[node] = 0;
    return false;
}

bool detectCycle(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pathvisited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfsCycle(graph, i, visited, pathvisited)) return true;
        }
    }
    return false;
}

int main(){

}
