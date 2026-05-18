// Bipartite Graph: A Graph that can be colored in 2 different colors such that
// no two adjacent nodes are of the same color
// Every graph is bipartite except a graph with an odd cycle.

#include <bits/stdc++.h>
using namespace std;

bool detectOddCycle(vector<vector<int>> &graph, vector<int> &visited, int vertex){
    // There are two colors - 0 and 1
    queue<int> q;
    vector<int> colors(graph.size(), -1);
    colors[vertex] = 0;
    q.push(vertex);
    visited[vertex] = 1;
    while(!q.empty()){
        int node = q.front();
        int color = colors[node];
        q.pop();

        for(auto i : graph[node]){
            if(!visited[i]){
                visited[i] = 1;
                int newcolor = color ^ 1;
                colors[i] = newcolor;
                q.push(i);
            }else{
                if(colors[i] == color) return true;
            }
        }
    }

    return false;
}

bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(detectOddCycle(graph, visited, i)) return false;
        }
        
    }
    return true;
}

int main(){
    vector<vector<int>> graph = {{1}, {0, 2, 5}, {1, 3}, {2, 4, 5}, {3}, {1, 3}};
    cout << isBipartite(graph);
    return 0;
}