class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m - 1 && y == n - 1) return effort;

            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};