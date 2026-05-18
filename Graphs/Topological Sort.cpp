/// Only valid for DAGs

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto i : graph[node]){
        if(!visited[i]){
            dfs(graph, i, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalsort(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> linearOrdering;
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(graph, i, visited, st);
        }
    }

    while(!st.empty()){
        linearOrdering.push_back(st.top());
        st.pop();
    }

    return linearOrdering;
}

int main(){

}