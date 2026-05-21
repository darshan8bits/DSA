class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto i : times){
            int src = i[0];
            int dest = i[1];
            int time = i[2];
            graph[src].push_back({dest, time});
        }
        vector<int> distance(n + 1, 1e9);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto i : graph[u]){
                int v = i.first;
                int edgeweight = i.second;
                int curr_dist = distance[u] + edgeweight;
                if(curr_dist < distance[v]){
                    distance[v] = curr_dist;
                    pq.push({curr_dist, v});
                }
            }
        }
        int maxm = 0;
        for(int i = 1; i <= n; i++){
            maxm = max(maxm, distance[i]);
        }

        return (maxm == 1e9) ? -1 : maxm;

    }
};