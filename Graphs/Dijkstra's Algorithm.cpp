#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstras(vector<vector<pair<int, int>>>& graph, int source){
    int n = graph.size();
    vector<int> distance(n, 1e9);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto i : graph[u]){
            int v = i.second;
            int edgeweight = i.first;
            if(d + edgeweight < distance[v]){
                distance[v] = d + edgeweight;
                pq.push({d + edgeweight, v});
            }
        }

    }
    return distance;
}

int main(){

}