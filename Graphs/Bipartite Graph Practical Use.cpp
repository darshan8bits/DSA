class Solution {
public:
    // check if the graph is bipartite or not!

    bool bfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& color, int node){
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = 1;
        color[node] = 0;
        while(!q.empty()){
            int x = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto i : graph[x]){
                if(!visited[i]){
                    visited[i] = 1;
                    color[i] = color[x] ^ 1;
                    q.push({i, x});
                }else{
                    if(color[i] == color[x]) return true;
                }
            }
        }
        return false;
    }

    bool detectNoOddCycle(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> color(n);
        vector<int> visited(n, 0);

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(bfs(graph, visited, color, i)) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // construct graph;
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < dislikes.size(); i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        return detectNoOddCycle(graph);

    }
};