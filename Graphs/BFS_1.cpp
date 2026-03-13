class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            for(int neighbours : adj[frontnode]){
                if(!visited[neighbours]){
                    if(neighbours == destination) return true;
                    q.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }

        return false;

    }
};