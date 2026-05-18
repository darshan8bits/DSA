// Detect Cycle in a Directed Graph using DFS
// Cycle detection for Undirected Graph does not work!

#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>> &graph, int node, vector<int> &visited, vector<int> &pathvisited, vector<int> &check){
    visited[node] = 1;
    pathvisited[node] = 1;
    check[node] = 0;

    for(auto it : graph[node]){
        if(!visited[it]){
            if(dfsCycle(graph, it, visited, pathvisited, check)){
                return true;
            }
        }else{
            if(pathvisited[it]) return true;
        }
    }
    check[node] = 1;
    pathvisited[node] = 0;
    return false;
}

vector<int> safeStates(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pathvisited(n, 0);
    vector<int> check(n, 0);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfsCycle(graph, i, visited, pathvisited, check);
        }
    }
    for(int i = 0; i < n; i++){
        if(check[i]) ans.push_back(i);
    }
    return ans;
}

int main(){

}
